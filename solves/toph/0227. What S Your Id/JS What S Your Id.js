t = +(r = readline)();
while (t--) {
    /**
     * @type [string]
     */
    let s = r();
    let depMap = { 115: "CSE", 141: "EEE", 116: "BBA", 117: "LLB", 114: "English", 111: "Economics" };
    let semMap = [undefined, "Spring", "Summer", "Autumn"];
    let res = s.match(/(?<Year>\d{2})(?<Sem>\d)-(?<Dep>\d+)-.+/);
    print(depMap[res.groups.Dep] + " " + semMap[res.groups.Sem] + " 20" + res.groups.Year);
}
