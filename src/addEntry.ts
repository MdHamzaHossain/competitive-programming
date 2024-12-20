import readline from "node:readline/promises";
import { stdin as input, stdout as output } from "node:process";
import { handleToph } from "./toph/tophHandler.js";
import { handleCodeforces } from "./codeforces/codeforcesHandler.js";

const r1 = readline.createInterface({ input, output });

main();
async function main() {
    // if (!process.env["CODEFORCES_API_KEY"]) {
    //     throw new Error("Please fill out your .env file!");
    // }

    while (true) {
        const url = await r1.question("Enter the url: \n");
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
            default: {
                console.log("That site is not supported yet");
            }
        }
    }
}
