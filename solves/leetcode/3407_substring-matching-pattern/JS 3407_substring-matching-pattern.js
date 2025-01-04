function hasMatch(s, p) {
    return s.match(p.replace("*", ".*"))?.length > 0;
}
/*
* TS
function hasMatch(s: string, p: string): boolean {
    return s.match(p.replace("*",".*"))?.length >0
};
*/
