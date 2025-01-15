#pragma once
#include <cinttypes>
#include <cstdint>
#include <iostream>

struct int2023_t {
  uint8_t nums[253]{0};
  int2023_t& operator=(const int2023_t& value);
};

static_assert(sizeof(int2023_t) <= 253, "Size of int2023_t must be no higher than 253 bytes");

bool is_negative(const int2023_t value);

int2023_t absolute_value(int2023_t value);

int2023_t from_int(int32_t i);

int2023_t from_string(const char* buff);

int2023_t from_uint8_array(const uint8_t arr[]);

int2023_t operator+(const int2023_t& lhs, const int2023_t& rhs);

int2023_t operator-(int2023_t& value);

int2023_t operator-(const int2023_t& lhs, const int2023_t& rhs);

int2023_t operator*(const int2023_t& lhs, const int2023_t& rhs);

int2023_t operator/(const int2023_t& lhs, const int2023_t& rhs);

bool operator<(const int2023_t& lhs, const int2023_t& rhs);

bool operator>(const int2023_t& lhs, const int2023_t& rhs);

bool operator<=(const int2023_t& lhs, const int2023_t& rhs);

bool operator>=(const int2023_t& lhs, const int2023_t& rhs);

bool operator==(const int2023_t& lhs, const int2023_t& rhs);

bool operator!=(const int2023_t& lhs, const int2023_t& rhs);
