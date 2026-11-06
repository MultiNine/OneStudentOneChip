error id: file://<WORKSPACE>/src/test/scala/HelloSpec.scala:
file://<WORKSPACE>/src/test/scala/HelloSpec.scala
empty definition using pc, found symbol in pc: 
empty definition using semanticdb
empty definition using fallback
non-local guesses:
	 -chisel3/dut/clock.
	 -dut/clock.
	 -scala/Predef.dut.clock.
offset: 354
uri: file://<WORKSPACE>/src/test/scala/HelloSpec.scala
text:
```scala
import chisel3._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.freespec.AnyFreeSpec

class HelloSpec extends AnyFreeSpec with ChiselSim {
  "Hello should blink" in {
    simulate(new Hello()) { dut =>
    dut.io.led.expect(0.U)  // 刚完成复位LED=0
    
    dut.clock.step(24999)   
    dut.io.led.expect(0.U)  // 经过24999个周期LED仍为0
dut.clock@@.step(24999)   
    dut.io.led.expect(0.U)  // 经过24999个周期LED仍为0


    }
  }
}
```


#### Short summary: 

empty definition using pc, found symbol in pc: 