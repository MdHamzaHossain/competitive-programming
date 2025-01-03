fun main() {
    val n = (readLine()!!.toInt())
    // val s = if ( (n < 1582 && n % 4 == 0) || (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) ) "I
    // can participate in LCPC" else "I have to travel back to the past";
    // println(s)
    println(
            if ((n < 1582 && n % 4 == 0) || (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)))
                    "I can participate in LCPC"
            else "I have to travel back to the past"
    )
}
