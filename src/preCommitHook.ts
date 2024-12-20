import { updateCodeforcesMd } from "./codeforces/codeforcesUpdateMD.js";
import { updateTophMd } from "./toph/tophUpdateMD.js";

async function main() {
    await updateTophMd();
    await updateCodeforcesMd();
}
main();
