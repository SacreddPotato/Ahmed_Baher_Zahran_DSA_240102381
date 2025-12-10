#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <ctime>

using namespace std;

// --- EGYPTIAN THEME DATA ---
struct Riddle {
    string question;
    string answer;
    string hint;
};

// A bank of Egypt-themed riddles
vector<Riddle> riddle_bank = {
    {"I speak without a mouth and hear without ears. I have nobody, but I come alive with the wind. What am I?", "echo", "It's a sound that bounces back."},
    {"I have cities, but no houses; forests, but no trees; and rivers, but no water. What am I?", "map", "You use me to find places."},
    {"What has to be broken before you can use it?", "egg", "It's something you eat for breakfast."},
    {"The more of this there is, the less you see. What is it?", "darkness", "It comes when the sun goes down."},
    {"I am not alive, but I grow; I don't have lungs, but I need air; I don't have a mouth, and yet water kills me. What am I?", "fire", "It's hot and can burn you."},
    {"What can run but never walks, has a mouth but never talks, has a head but never weeps, has a bed but never sleeps?", "river", "It's a body of water that flows."},
    {"I am always hungry, I must always be fed. The finger I touch, will soon turn red. What am I?", "fire", "It's hot and can burn you."},
    {"What has keys but can't open locks?", "piano", "It's a musical instrument."},
    {"What comes once in a minute, twice in a moment, but never in a thousand years?", "m", "It's a letter in the alphabet."},
    {"I have branches, but no fruit, trunk or leaves. What am I?", "bank", "It's a place where you keep money."}
};

struct RoomNode {
    int id;
    int layer;
    string type;     // "Normal", "ENTRANCE", "ESCAPE"
    bool solved;     // Tracks if the player has been here and won
    Riddle puzzle;   // The specific puzzle for this room
    
    vector<RoomNode*> routes; 

    RoomNode(int id, int layer) : id(id), layer(layer), type("Normal"), solved(false) {}

    void add_route(RoomNode* node) {
        if (node->id != this->id) {
            bool exists = false;
            for (RoomNode* neighbor : routes) {
                if (neighbor->id == node->id) exists = true;
            }
            if (!exists) routes.push_back(node);
        }
    }
};

class DungeonGraph {
private:
    int depth;
    int max_width;
    vector<RoomNode*> all_nodes;
    RoomNode* start_node;
    RoomNode* end_node;

    // Helper to get a random riddle
    Riddle get_random_riddle() {
        static mt19937 gen(time(0));
        uniform_int_distribution<> dist(0, riddle_bank.size() - 1);
        return riddle_bank[dist(gen)];
    }

public:
    DungeonGraph(int depth, int max_width) : depth(depth), max_width(max_width), start_node(nullptr), end_node(nullptr) {}

    ~DungeonGraph() {
        for (RoomNode* node : all_nodes) delete node;
    }

    void generate() {
        int current_id = 0;
        vector<vector<RoomNode*>> layers;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> width_dist(1, max_width);
        uniform_real_distribution<> prob_dist(0.0, 1.0);

        // --- STEP 1: Create Nodes ---
        start_node = new RoomNode(current_id++, 0);
        start_node->type = "ENTRANCE";
        start_node->solved = true; // Entrance is safe
        all_nodes.push_back(start_node);
        layers.push_back({start_node});

        for (int d = 1; d < depth; ++d) {
            vector<RoomNode*> layer_nodes;
            int width = width_dist(gen);
            for (int w = 0; w < width; ++w) {
                RoomNode* new_node = new RoomNode(current_id++, d);
                new_node->puzzle = get_random_riddle(); // Assign riddle
                all_nodes.push_back(new_node);
                layer_nodes.push_back(new_node);
            }
            layers.push_back(layer_nodes);
        }

        end_node = new RoomNode(current_id++, depth);
        end_node->type = "ESCAPE";
        all_nodes.push_back(end_node);
        layers.push_back({end_node});

        // --- STEP 2: The Spine ---
        for (size_t i = 0; i < layers.size() - 1; ++i) {
            uniform_int_distribution<> src_dist(0, layers[i].size() - 1);
            uniform_int_distribution<> tgt_dist(0, layers[i+1].size() - 1);
            layers[i][src_dist(gen)]->add_route(layers[i+1][tgt_dist(gen)]);
        }

        // --- STEP 3: Graph Logic (Red Lines) ---
        for (RoomNode* node : all_nodes) {
            if (node == end_node) continue;

            int target_routes = (node->type == "Square") ? 1 : 2; // Simplified logic for demo
            int attempts = 0;

            while (node->routes.size() < target_routes && attempts < 10) {
                attempts++;
                double roll = prob_dist(gen);
                RoomNode* target_node = nullptr;

                if (roll < 0.7 && node->layer + 1 < layers.size()) {
                    // Normal
                    uniform_int_distribution<> d(0, layers[node->layer + 1].size() - 1);
                    target_node = layers[node->layer + 1][d(gen)];
                } else if (roll < 0.85 && node->layer + 2 < layers.size()) {
                    // Shortcut (Red)
                    uniform_int_distribution<> layer_d(node->layer + 2, layers.size() - 1);
                    int t_layer = layer_d(gen);
                    uniform_int_distribution<> node_d(0, layers[t_layer].size() - 1);
                    target_node = layers[t_layer][node_d(gen)];
                } else if (node->layer > 0) {
                    // Trap (Red)
                    uniform_int_distribution<> layer_d(0, node->layer - 1);
                    int t_layer = layer_d(gen);
                    uniform_int_distribution<> node_d(0, layers[t_layer].size() - 1);
                    target_node = layers[t_layer][node_d(gen)];
                }

                if (target_node) node->add_route(target_node);
            }
            if (node->routes.empty() && node->layer + 1 < layers.size()) {
                node->add_route(layers[node->layer + 1][0]);
            }
        }
    }

    // --- GAMEPLAY FUNCTION ---
    void play() {
        RoomNode* current = start_node;
        int score = 0;
        int moves = 0;
        string input;

        cout << "============================================" << endl;
        cout << "   MYSTERY LIBRARY: CURSE OF THE PHARAOH    " << endl;
        cout << "============================================" << endl;
        cout << "You stand at the green entrance of a shifting labyrinth." << endl;
        cout << "Find the Yellow Room to escape." << endl; 
        cout << "But beware... some paths lead backwards." << endl << endl;

        while (current != nullptr) {
            cout << "--------------------------------------------" << endl;
            cout << "CURRENT LOCATION: Room " << current->id << " (Depth: " << current->layer << ")" << endl;
            
            // Check Victory
            if (current->type == "ESCAPE") {
                cout << "\n*** YOU SEE THE GOLDEN LIGHT OF DAY! ***" << endl;
                cout << "You have escaped the library!" << endl;
                cout << "Final Score: " << score << endl;
                cout << "Total Moves: " << moves << endl;
                break;
            }

            // Room Logic
            if (current->id != start_node->id) { // Skip logic for start node
                if (current->solved) {
                    cout << ">> " << "It seems like we've been here before..." << endl;
                    cout << ">> The hieroglyphs on the wall are already glowing. The puzzle is solved." << endl;
                } else {
                    cout << "A spirit blocks your path and whispers a riddle:" << endl;
                    cout << "\"" << current->puzzle.question << "\"" << endl;
                    
                    bool solved_room = false;
                    while (!solved_room) {
                        cout << "Action [(a)nswer / (h)int / (g)ive up]: ";
                        cin >> input;

                        // Lowercase input
                        transform(input.begin(), input.end(), input.begin(), ::tolower);

                        if (input == "a" || input == "answer") {
                            cout << "Your answer: ";
                            string user_ans;
                            cin >> user_ans; // simple one word answers
                            transform(user_ans.begin(), user_ans.end(), user_ans.begin(), ::tolower);
                            
                            if (user_ans == current->puzzle.answer) {
                                cout << "The spirit bows. 'You may pass.'" << endl;
                                score += 100;
                                current->solved = true;
                                solved_room = true;
                            } else {
                                cout << "The spirit shakes its head. 'Incorrect.'" << endl;
                                score -= 10;
                            }
                        } else if (input == "h" || input == "hint") {
                            cout << "HINT: " << current->puzzle.hint << endl;
                            score -= 20; // Hint cost
                        } else if (input == "g" || input == "give") {
                            cout << "You push past the spirit, losing a piece of your soul." << endl;
                            score -= 50;
                            current->solved = true; // Mark solved but low points
                            solved_room = true;
                        }
                    }
                }
            }

            // Navigation
            cout << "\nYou see " << current->routes.size() << " passages forward." << endl;
            for (size_t i = 0; i < current->routes.size(); ++i) {
                cout << "[" << i + 1 << "] Passage " << i + 1 << endl; 
                // Note: We intentionally hide if it's a Trap or Shortcut!
            }

            int choice = -1;
            while (choice < 1 || choice > (int)current->routes.size()) {
                cout << "Choose a path (1-" << current->routes.size() << "): ";
                if (!(cin >> choice)) { // catch non-integer input
                    cin.clear();
                    cin.ignore(10000, '\n');
                    choice = -1;
                }
            }

            // Move
            current = current->routes[choice - 1];
            moves++;
            cout << "You travel through the dark corridor..." << endl;
        }
    }
};

int main() {
    // Generate a dungeon
    // Depth 6, Width 3
    DungeonGraph dungeon(6, 3);
    dungeon.generate();
    
    // Start the game
    dungeon.play();

    return 0;
}