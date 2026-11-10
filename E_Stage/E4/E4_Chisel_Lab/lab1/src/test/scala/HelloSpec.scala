import  chisel3._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.freespec.AnyFreeSpec

class HelloSpec extends AnyFreeSpec with ChiselSim {
  "Hello should blink" in {
    simulate(new Hello()) { dut =>
    dut.io.led.expect(0.U)  // 刚完成复位LED=0
    
    dut.clock.step(24999)   // 经过24999个周期LED仍为0
    dut.io.led.expect(0.U)  // LED仍为0

    dut.clock.step(1)       // 再经过1个周期
    dut.io.led.expect(1.U)  // LED变为1

    dut.clock.step(25000)   // 再经过25000个周期
    dut.io.led.expect(0.U)  // LED变回0
    }
  }
}