    /**
     * @param {number[]} bits
     * @return {boolean}
     */
    var isOneBitCharacter = function(bits) {
        let helper = false;
        for (let i = 0; i < bits.length; i++) {
            if (i == bits.length - 1 && helper) {
                return false;
            }
            
            if (bits[i] === 1 && !helper) {
                helper = true;
                continue;
            }

            if (helper) {
                helper = false;
            }
        }

        return true;
    };

console.log(isOneBitCharacter([1,1,1,0]));