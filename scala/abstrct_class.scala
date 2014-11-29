abstract class Person(val name: String) {
  val age = 0
  println("in Person: " + age)
  def greetings
}

class Coder(name: String) extends {
  override val age = 20
} with Person(name) {
  def greetings = {
    println("hello coder " + name)
  }
}

class Worker(override val name: String) extends Person(name) {
  def greetings = {
    println("hello worker " + name)
  }

  def test() = {
    println("test")
  }
}

object Main extends App {
  val p = new Coder("crackcell")
  p.greetings
  val w = new Worker("crackcell")
  w.greetings
  w.test()
}
