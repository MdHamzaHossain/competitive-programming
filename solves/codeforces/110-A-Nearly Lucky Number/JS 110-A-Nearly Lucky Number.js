a = readline();
res = ("" + (a.match(/(7|4)/gim) || []).length).match(/[^74]/);
print(res ? "NO" : "YES");
