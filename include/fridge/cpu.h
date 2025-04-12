#pragma once

#include <array>
#include <cstdint>

struct FlagsRegister {
    bool z : 1;
    bool n : 1;
    bool h : 1;
    bool c : 1;
};

struct Registers {
    union {
        struct {
            uint8_t afLo;
            uint8_t afHi;
        };
        uint16_t af;
    };
    union {
        struct {
            uint8_t bcLo;
            uint8_t bcHi;
        };
        uint16_t bc;
    };
    union {
        struct {
            uint8_t deLo;
            uint8_t deHi;
        };
        uint16_t de;
    };
    union {
        struct {
            uint8_t hlLo;
            uint8_t hlHi;
        };
        uint16_t hl;
    };
    uint16_t sp;
    uint16_t pc;
    FlagsRegister flags;
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
    MemoryBus mem;
};
