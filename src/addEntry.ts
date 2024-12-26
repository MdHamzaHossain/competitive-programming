import readline from "node:readline/promises";
import { stdin as input, stdout as output } from "node:process";
import { handleToph } from "./toph/tophHandler.js";
import { fetchCodeforcesData, handleCodeforces } from "./codeforces/codeforcesHandler.js";
import { fetchLeetcodeData, handleLeetcode } from "./leetcode/leetcodeHandler.js";
import { updateEveryMD } from "./updateEveryMD.js";

const r1 = readline.createInterface({ input, output });

main();
const updateCommand = "update";
async function main() {
    // if (!process.env["CODEFORCES_API_KEY"]) {
    //     throw new Error("Please fill out your .env file!");
    // }
    console.log("Fetching Data....");
    await setup();
    console.log(`Enter "${updateCommand}" to update all the README when you're done\n`);

    while (true) {
        const url = await r1.question("Enter the url: \n");

        if (url.toLowerCase() === "update") {
            await updateEveryMD();
            continue;
        }

        const { hostname } = new URL(url);
        switch (hostname) {
            case "toph.co": {
                await handleToph(url, r1);
                break;
            }
            case "codeforces.com": {
                await handleCodeforces(url, r1);
                break;
            }
            case "leetcode.com": {
                await handleLeetcode(url, r1);
                break;
            }
            default: {
                console.log("That site is not supported yet");
            }
        }
    }
}
async function setup() {
    await fetchCodeforcesData();
    await fetchLeetcodeData();
}
