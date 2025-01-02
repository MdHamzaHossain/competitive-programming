fun main() {
    var n = readln()!!.toInt()
    val a = readln()!!.split(" ")
    var max = 0
    while (n-- > 0) {
        if (a[n].toInt() > max) max = a[n].toInt()
    }
    // for(i in a.)
    println(max)
}
