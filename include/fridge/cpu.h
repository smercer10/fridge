#pragma once

#include <array>
#include <cstdint>

enum class R8 : uint8_t {
    a,
    b,
    c,
    d,
    e,
    h,
    l
};

enum class R16 : uint8_t {
    af,
    bc,
    de,
    hl,
};

struct FlagsRegister {
    bool z : 1;
    bool n : 1;
    bool h : 1;
    bool c : 1;
};

struct Registers {
    union {
        struct {
            uint8_t f;
            uint8_t a;
        };
        uint16_t af;
    };
    union {
        struct {
            uint8_t c;
            uint8_t b;
        };
        uint16_t bc;
    };
    union {
        struct {
            uint8_t e;
            uint8_t d;
        };
        uint16_t de;
    };
    union {
        struct {
            uint8_t l;
            uint8_t h;
        };
        uint16_t hl;
    };
    uint16_t sp;
    uint16_t pc;
};

class MemoryBus {
public:
    [[nodiscard]] uint8_t read(uint16_t addr) const noexcept
    {
        return mem[addr];
    }

    void write(uint16_t addr, uint8_t val) noexcept
    {
        mem[addr] = val;
    }

private:
    static constexpr std::size_t memSize { 0x10000 }; // 64KB memory space.
    std::array<uint8_t, memSize> mem {};
};

class CPU {
public:
private:
    Registers reg {};
    FlagsRegister flags {};
    MemoryBus mem;

    [[nodiscard]] uint8_t cInt() const noexcept
    {
        return flags.c ? 1 : 0;
    }

    [[nodiscard]] uint8_t getR8(R8 r8) const noexcept;
    void setR8(R8 r8, uint8_t val) noexcept;

    [[nodiscard]] uint16_t getR16(R16 r16) const noexcept;
    void setR16(R16 r16, uint16_t val) noexcept;
};
