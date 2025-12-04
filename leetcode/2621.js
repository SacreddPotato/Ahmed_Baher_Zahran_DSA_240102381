/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    const time = await new Promise(resolve => {
        setTimeout(() => {
            resolve(millis);
        }, millis)
    });

    return time
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */

console.log(sleep(333))