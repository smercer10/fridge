#include "fridge/cpu.h"

[[nodiscard]] uint8_t CPU::getR8(R8 r8) const noexcept
{
    using enum R8;
    switch (r8) {
    case a:
        return reg.a;
    case b:
        return reg.b;
    case c:
        return reg.c;
    case d:
        return reg.d;
    case e:
        return reg.e;
    case h:
        return reg.h;
    case l:
        return reg.l;
    }
    return 0;
}

void CPU::setR8(R8 r8, uint8_t val) noexcept
{
    using enum R8;
    switch (r8) {
    case a:
        reg.a = val;
        return;
    case b:
        reg.b = val;
        return;
    case c:
        reg.c = val;
        return;
    case d:
        reg.d = val;
        return;
    case e:
        reg.e = val;
        return;
    case h:
        reg.h = val;
        return;
    case l:
        reg.l = val;
        return;
    }
}

[[nodiscard]] uint16_t CPU::getR16(R16 r16) const noexcept
{
    using enum R16;
    switch (r16) {
    case af:
        return reg.af;
    case bc:
        return reg.bc;
    case de:
        return reg.de;
    case hl:
        return reg.hl;
    }
    return 0;
}

void CPU::setR16(R16 r16, uint16_t val) noexcept
{
    using enum R16;
    switch (r16) {
    case af:
        reg.af = val;
        return;
    case bc:
        reg.bc = val;
        return;
    case de:
        reg.de = val;
        return;
    case hl:
        reg.hl = val;
        return;
    }
}
