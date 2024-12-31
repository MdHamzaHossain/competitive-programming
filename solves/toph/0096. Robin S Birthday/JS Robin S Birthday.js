a = +(r = readline)();
print(r().match(/(00|11)/g)?.length ? "Change needed" : "No change needed");
