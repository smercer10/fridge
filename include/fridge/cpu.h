#pragma once

#include <array>
#include <cstdint>
#include <functional>

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

struct FlagsRegister {
    bool z : 1;
    bool n : 1;
    bool h : 1;
    bool c : 1;
};

class MemoryBus {
public:
    [[nodiscard]] uint8_t read(uint16_t addr) const noexcept { return mem[addr]; }
    void write(uint16_t addr, uint8_t val) noexcept { mem[addr] = val; }

private:
    std::array<uint8_t, 0x10000> mem {}; // 64KB memory space.
};

class CPU {
public:
    CPU() noexcept;

    void adc(uint8_t val) noexcept;

private:
    Registers reg {};
    FlagsRegister flags {};
    MemoryBus mem;

    std::array<std::function<void(CPU&)>, 256> opTable;
    void initOpTable() noexcept;

    [[nodiscard]] uint8_t cBit() const noexcept { return flags.c ? 1 : 0; }
};
