#pragma once

#include "types.h"

// ビッグエンディアンとリトルエンディアンの相互変換 (16ビット)
static inline uint16_t swap16(uint16_t x) {
    return ((x & 0xff00) >> 8) | ((x & 0x00ff) << 8);
}

// ビッグエンディアンとリトルエンディアンの相互変換 (32ビット)
static inline uint32_t swap32(uint32_t x) {
    return ((x & 0xff000000) >> 24) | ((x & 0x00ff0000) >> 8)
           | ((x & 0x0000ff00) << 8) | ((x & 0x000000ff) << 24);
}

static inline uint16_t into_le16(uint16_t x) {
    return swap16(x);  // ビックエンディアン -> リトルエンディアン
}
static inline uint32_t into_le32(uint32_t x) {
    return swap32(x);  // ビックエンディアン -> リトルエンディアン
}
static inline uint16_t from_le16(uint16_t x) {
    return swap16(x);  // リトルエンディアン -> ビックエンディアン
}
static inline uint32_t from_le32(uint32_t x) {
    return swap32(x);  // リトルエンディアン -> ビックエンディアン
}