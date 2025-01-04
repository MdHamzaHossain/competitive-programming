fun main() {
    val n = readLine()!!.toInt()
    val m = readLine()!!.toInt()
    println(if (n > m) "Champion\nRunner up" else "Runner up\nChampion")
}
