// SPDX-FileCopyrightText: Copyright (c) 2022 merryhime <https://mary.rs>
// SPDX-License-Identifier: MIT

#pragma once

namespace oaknut {

struct PostIndexed {};

struct PreIndexed {};

enum class LslSymbol {
    LSL,
};

enum class Cond {
    EQ,
    NE,
    CS,
    CC,
    MI,
    PL,
    VS,
    VC,
    HI,
    LS,
    GE,
    LT,
    GT,
    LE,
    AL,
    NV,
    HS = CS,
    LO = CC,
};

constexpr Cond invert(Cond c)
{
    return static_cast<Cond>(static_cast<unsigned>(c) ^ 1);
}

enum class AddSubExt {
    UXTB,
    UXTH,
    UXTW,
    UXTX,
    SXTB,
    SXTH,
    SXTW,
    SXTX,
    LSL,  // UXTW (32-bit) or UXTX (64-bit)
};

enum class IndexExt {
    UXTW = 0b010,
    LSL = 0b011,
    SXTW = 0b110,
    SXTX = 0b111,
};

enum class AddSubShift {
    LSL,
    LSR,
    ASR,
};

enum class LogShift {
    LSL,
    LSR,
    ASR,
    ROR,
};

enum class PstateField {
    UAO = 0b000'011,  // ARMv8.2-UAO
    PAN = 0b000'100,  // ARMv8.1-PAN
    SPSel = 0b000'101,
    DIT = 0b011'010,  // ARMv8.4-DIT
    DAIFSet = 0b011'110,
    DAIFClr = 0b011'111,
};

enum class SystemReg {
};

enum class AtOp {
    S1E1R = 0b000'0'000,
    S1E1W = 0b000'0'001,
    S1E0R = 0b000'0'010,
    S1E0W = 0b000'0'011,
    S1E1RP = 0b000'1'000,  // ARMv8.2-ATS1E1
    S1E1WP = 0b000'1'001,  // ARMv8.2-ATS1E1
    S1E2R = 0b100'0'000,
    S1E2W = 0b100'0'001,
    S12E1R = 0b100'0'100,
    S12E1W = 0b100'0'101,
    S12E0R = 0b100'0'110,
    S12E0W = 0b100'0'111,
    S1E3R = 0b110'0'000,
    S1E3W = 0b110'0'001,
};

enum class BarrierOp {
    SY = 0b1111,
    ST = 0b1110,
    LD = 0b1101,
    ISH = 0b1011,
    ISHST = 0b1010,
    ISHLD = 0b1001,
    NSH = 0b0111,
    NSHST = 0b0110,
    NSHLD = 0b0101,
    OSH = 0b0011,
    OSHST = 0b0010,
    OSHLD = 0b0001,
};

enum class DcOp {
    IVAC = 0b000'0110'001,
    ISW = 0b000'0110'010,
    CSW = 0b000'1010'010,
    CISW = 0b000'1110'010,
    ZVA = 0b011'0100'001,
    CVAC = 0b011'1010'001,
    CVAU = 0b011'1011'001,
    CVAP = 0b011'1100'001,  // ARMv8.2-DCPoP
    CIVAC = 0b011'1110'001,
};

enum class IcOp {
    IALLUIS = 0b000'0001'000,
    IALLU = 0b000'0101'000,
    IVAU = 0b011'0101'001,
};

enum class PrfOp {
    PLDL1KEEP = 0b00'00'0,
    PLDL1STRM = 0b00'00'1,
    PLDL2KEEP = 0b00'01'0,
    PLDL2STRM = 0b00'01'1,
    PLDL3KEEP = 0b00'10'0,
    PLDL3STRM = 0b00'10'1,
    PLIL1KEEP = 0b01'00'0,
    PLIL1STRM = 0b01'00'1,
    PLIL2KEEP = 0b01'01'0,
    PLIL2STRM = 0b01'01'1,
    PLIL3KEEP = 0b01'10'0,
    PLIL3STRM = 0b01'10'1,
    PSTL1KEEP = 0b10'00'0,
    PSTL1STRM = 0b10'00'1,
    PSTL2KEEP = 0b10'01'0,
    PSTL2STRM = 0b10'01'1,
    PSTL3KEEP = 0b10'10'0,
    PSTL3STRM = 0b10'10'1,
};

enum class TlbiOp {
    VMALLE1OS = 0b000'0001'000,  // ARMv8.4-TLBI
    VAE1OS = 0b000'0001'001,     // ARMv8.4-TLBI
    ASIDE1OS = 0b000'0001'010,   // ARMv8.4-TLBI
    VAAE1OS = 0b000'0001'011,    // ARMv8.4-TLBI
    VALE1OS = 0b000'0001'101,    // ARMv8.4-TLBI
    VAALE1OS = 0b000'0001'111,   // ARMv8.4-TLBI
    RVAE1IS = 0b000'0010'001,    // ARMv8.4-TLBI
    RVAAE1IS = 0b000'0010'011,   // ARMv8.4-TLBI
    RVALE1IS = 0b000'0010'101,   // ARMv8.4-TLBI
    RVAALE1IS = 0b000'0010'111,  // ARMv8.4-TLBI
    VMALLE1IS = 0b000'0011'000,
    VAE1IS = 0b000'0011'001,
    ASIDE1IS = 0b000'0011'010,
    VAAE1IS = 0b000'0011'011,
    VALE1IS = 0b000'0011'101,
    VAALE1IS = 0b000'0011'111,
    RVAE1OS = 0b000'0101'001,    // ARMv8.4-TLBI
    RVAAE1OS = 0b000'0101'011,   // ARMv8.4-TLBI
    RVALE1OS = 0b000'0101'101,   // ARMv8.4-TLBI
    RVAALE1OS = 0b000'0101'111,  // ARMv8.4-TLBI
    RVAE1 = 0b000'0110'001,      // ARMv8.4-TLBI
    RVAAE1 = 0b000'0110'011,     // ARMv8.4-TLBI
    RVALE1 = 0b000'0110'101,     // ARMv8.4-TLBI
    RVAALE1 = 0b000'0110'111,    // ARMv8.4-TLBI
    VMALLE1 = 0b000'0111'000,
    VAE1 = 0b000'0111'001,
    ASIDE1 = 0b000'0111'010,
    VAAE1 = 0b000'0111'011,
    VALE1 = 0b000'0111'101,
    VAALE1 = 0b000'0111'111,
    IPAS2E1IS = 0b100'0000'001,
    RIPAS2E1IS = 0b100'0000'010,  // ARMv8.4-TLBI
    IPAS2LE1IS = 0b100'0000'101,
    RIPAS2LE1IS = 0b100'0000'110,   // ARMv8.4-TLBI
    ALLE2OS = 0b100'0001'000,       // ARMv8.4-TLBI
    VAE2OS = 0b100'0001'001,        // ARMv8.4-TLBI
    ALLE1OS = 0b100'0001'100,       // ARMv8.4-TLBI
    VALE2OS = 0b100'0001'101,       // ARMv8.4-TLBI
    VMALLS12E1OS = 0b100'0001'110,  // ARMv8.4-TLBI
    RVAE2IS = 0b100'0010'001,       // ARMv8.4-TLBI
    RVALE2IS = 0b100'0010'101,      // ARMv8.4-TLBI
    ALLE2IS = 0b100'0011'000,
    VAE2IS = 0b100'0011'001,
    ALLE1IS = 0b100'0011'100,
    VALE2IS = 0b100'0011'101,
    VMALLS12E1IS = 0b100'0011'110,
    IPAS2E1OS = 0b100'0100'000,  // ARMv8.4-TLBI
    IPAS2E1 = 0b100'0100'001,
    RIPAS2E1 = 0b100'0100'010,    // ARMv8.4-TLBI
    RIPAS2E1OS = 0b100'0100'011,  // ARMv8.4-TLBI
    IPAS2LE1OS = 0b100'0100'100,  // ARMv8.4-TLBI
    IPAS2LE1 = 0b100'0100'101,
    RIPAS2LE1 = 0b100'0100'110,    // ARMv8.4-TLBI
    RIPAS2LE1OS = 0b100'0100'111,  // ARMv8.4-TLBI
    RVAE2OS = 0b100'0101'001,      // ARMv8.4-TLBI
    RVALE2OS = 0b100'0101'101,     // ARMv8.4-TLBI
    RVAE2 = 0b100'0110'001,        // ARMv8.4-TLBI
    RVALE2 = 0b100'0110'101,       // ARMv8.4-TLBI
    ALLE2 = 0b100'0111'000,
    VAE2 = 0b100'0111'001,
    ALLE1 = 0b100'0111'100,
    VALE2 = 0b100'0111'101,
    VMALLS12E1 = 0b100'0111'110,
    ALLE3OS = 0b110'0001'000,   // ARMv8.4-TLBI
    VAE3OS = 0b110'0001'001,    // ARMv8.4-TLBI
    VALE3OS = 0b110'0001'101,   // ARMv8.4-TLBI
    RVAE3IS = 0b110'0010'001,   // ARMv8.4-TLBI
    RVALE3IS = 0b110'0010'101,  // ARMv8.4-TLBI
    ALLE3IS = 0b110'0011'000,
    VAE3IS = 0b110'0011'001,
    VALE3IS = 0b110'0011'101,
    RVAE3OS = 0b110'0101'001,   // ARMv8.4-TLBI
    RVALE3OS = 0b110'0101'101,  // ARMv8.4-TLBI
    RVAE3 = 0b110'0110'001,     // ARMv8.4-TLBI
    RVALE3 = 0b110'0110'101,    // ARMv8.4-TLBI
    ALLE3 = 0b110'0111'000,
    VAE3 = 0b110'0111'001,
    VALE3 = 0b110'0111'101,
};

}  // namespace oaknut
