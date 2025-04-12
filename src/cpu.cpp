#include "fridge/cpu.h"

CPU::CPU() noexcept
{
    initOpTable();
}

void CPU::initOpTable() noexcept
{
    opTable[0x88] = [](CPU& cpu) { cpu.adc(cpu.reg.b); };
    opTable[0x89] = [](CPU& cpu) { cpu.adc(cpu.reg.c); };
    opTable[0x8A] = [](CPU& cpu) { cpu.adc(cpu.reg.d); };
    opTable[0x8B] = [](CPU& cpu) { cpu.adc(cpu.reg.e); };
    opTable[0x8C] = [](CPU& cpu) { cpu.adc(cpu.reg.h); };
    opTable[0x8D] = [](CPU& cpu) { cpu.adc(cpu.reg.l); };
    opTable[0x8E] = [](CPU& cpu) { cpu.adc(cpu.mem.read(cpu.reg.hl)); };
    opTable[0x8F] = [](CPU& cpu) { cpu.adc(cpu.reg.a); };
    opTable[0xCE] = [](CPU& cpu) { cpu.adc(cpu.mem.read(cpu.reg.pc++)); };
}

void CPU::adc(uint8_t val) noexcept
{
    const auto a { reg.a };
    const auto c { cBit() };

    const uint16_t res16 = static_cast<uint16_t>(a) + val + c;
    const auto res8 { static_cast<uint8_t>(res16) };

    flags.z = res8 == 0;
    flags.n = false;
    flags.h = ((a & 0x0F) + (val & 0x0F) + c) > 0xFF; // NOLINT(hicpp-signed-bitwise)
    flags.c = res16 > 0xFF;

    reg.a = res8;
}
