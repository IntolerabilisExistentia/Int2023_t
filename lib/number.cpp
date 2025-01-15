#include "number.h"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <strings.h>

int NUMS_SIZE = 253;
int SYSTEM_BASE = 256;
int2023_t NULL_2023;

bool is_negative(const int2023_t value) {
  if (value.nums[NUMS_SIZE - 1] >> 7 == 1) {
    return true;
  }
  return false;
}

int2023_t bin_division(const int2023_t& num) {
  int2023_t changeable_num = absolute_value(num);
  int start = NUMS_SIZE - 1;
  while (changeable_num.nums[start] == 0) {
    --start;
  }
  int buff = 0;
  int2023_t result;
  for (int i = start; i >= 0; --i) {
    buff += changeable_num.nums[i];
    result.nums[i] += buff / 2;
    buff = buff % 2 * SYSTEM_BASE;
  }
  if (is_negative(num) && !is_negative(result)) {
    return -result;
  }
  return result;
}

int2023_t absolute_value(int2023_t value) {
  if (!is_negative(value)) {
    return value;
  }
  for (int i = 0; i < NUMS_SIZE; ++i) {
    value.nums[i] ^= SYSTEM_BASE - 1; 
  }
  value.nums[0] += 1;
  return value;
}

int2023_t from_int(int32_t i) {
  bool negative_flag = false;
  if (i < 0) {
    i = -i;
    negative_flag = true;
  }
  int2023_t result;
  int index = 0;
  while (i != 0) {
    result.nums[index] = i % SYSTEM_BASE;
    ++index;
    i /= SYSTEM_BASE;
  }
  if (negative_flag) {
    return -result;
  }
  return result;
}

int2023_t from_string(const char* str) {
  int2023_t result;
  int start = 0;
  bool negative_flag = false;
  int2023_t ten = from_int(10);
  if (str[0] == '-') {
    ++start;
    negative_flag = true;
  }
  int len = strlen(str);
  for (int i = start; i < len; ++i) {
    result = result * ten;
    int num = str[i] - '0';
    int2023_t tmp = from_int(num);
    result = result + tmp;
  }
  if (negative_flag) {
    return -result;
  }
  return result;  
}

int2023_t from_uint8_array(const uint8_t *arr) {
  int2023_t result;
  for (int i = 0; i < std::min(int(sizeof(arr)), NUMS_SIZE); ++i) {
    result.nums[i] = arr[i];
  }
  return result;
}

int2023_t operator+(const int2023_t& lhs, const int2023_t& rhs) {
  if (!is_negative(lhs) && is_negative(rhs)) {
    return lhs - absolute_value(rhs);
  }
  if (is_negative(lhs) && !is_negative(rhs)) {
    return rhs - absolute_value(lhs);
  }
  int2023_t result;
  int2023_t absolute_lhs = absolute_value(lhs);
  int2023_t absolute_rhs = absolute_value(rhs);
  int buff = 0;
  for (int i = 0; i < NUMS_SIZE; ++i) {
    result.nums[i] = absolute_lhs.nums[i] + absolute_rhs.nums[i] + buff;
    if (result.nums[i] < absolute_lhs.nums[i] || result.nums[i] < absolute_rhs.nums[i]) {
      buff = 1;
    } else {
      buff = 0;
    }
  }
  if (is_negative(lhs) && is_negative(rhs)) {
    return -result;
  }
  return result;
}

int2023_t operator-(int2023_t& value) {
  if (is_negative(value)) {
    return absolute_value(value);
  }
  for (int i = 0; i < NUMS_SIZE; ++i) {
    value.nums[i] ^= SYSTEM_BASE - 1; 
  }
  value.nums[0] += 1;
  return value;
}

int2023_t operator-(const int2023_t& lhs, const int2023_t& rhs) {
  if (is_negative(lhs) && !is_negative(rhs)) {
    int2023_t tmp = (absolute_value(lhs) + absolute_value(rhs));
    return -tmp;
  }
  if (!is_negative(lhs) && is_negative(rhs)) {
    return lhs + absolute_value(rhs);
  }
  int2023_t result;
  int2023_t bigger;
  int2023_t lower;
  bool negative_flag = false;
  int buff = 0;
  if (absolute_value(lhs) == absolute_value(rhs)) {
    return result;
  }
  if (absolute_value(lhs) > absolute_value(rhs)) {
    bigger = absolute_value(lhs);
    lower = absolute_value(rhs);
  } else {
    negative_flag = true;
    bigger = absolute_value(rhs);
    lower = absolute_value(lhs);
  }
  for (int i = 0; i < NUMS_SIZE; ++i) {
    result.nums[i] = bigger.nums[i] - lower.nums[i] - buff;
    if (result.nums[i] >= bigger.nums[i] && lower.nums[i] - buff != 0) {
      buff = 1;
    } else {
      buff = 0;
    }
  }
  if (is_negative(lhs) && is_negative(rhs)) {
    negative_flag ^= 1;
  }
  if (negative_flag) {
    return -result;
  }
  return result;
}

int2023_t operator*(const int2023_t& lhs, const int2023_t& rhs) {
  int2023_t result;
  if (lhs == NULL_2023 || rhs == NULL_2023) {
    return result;
  }
  int2023_t absolute_lhs = absolute_value(lhs);
  int2023_t absolute_rhs = absolute_value(rhs);
  int add_buff = 0;
  int start_index = 0;
  for (int i = 0; i < NUMS_SIZE; ++i) {
    int2023_t buff;
    if (absolute_lhs.nums[i] == 0) {
      ++start_index;
    } else {
      for (int j = 0; j < NUMS_SIZE; ++j) {
        int curr = absolute_lhs.nums[i] * absolute_rhs.nums[j] + add_buff;
        if (start_index + j < NUMS_SIZE) {
          buff.nums[start_index + j] = curr % SYSTEM_BASE;
          add_buff = curr / SYSTEM_BASE;
        }
      }
      result = result + buff;
      ++start_index;
    }
  }
  if ((!is_negative(lhs) && is_negative(rhs)) || (is_negative(lhs) && !is_negative(rhs))) {
    return -result;
  }
  return result;
}

int2023_t operator/(const int2023_t& lhs, const int2023_t& rhs) {
  int2023_t result;
  if (absolute_value(rhs) == from_int(1)) {
    result = lhs;
    if ((is_negative(lhs) && !is_negative(rhs)) || (!is_negative(lhs) && is_negative(rhs))) {
      return -result;
    }
    return result;
  }
  int2023_t low = NULL_2023;
  int2023_t high = absolute_value(lhs);
  int2023_t x = absolute_value(lhs);
  int2023_t y = absolute_value(rhs);
  if (y == NULL_2023) {
    throw std::invalid_argument("Division by zero");
  }
  if (x < y) {
    return result;
  }
  while (true) {
    int2023_t mid = low + bin_division(high - low);
    if (x - mid * y > y) {
      low = mid;
    } else if (y * mid - x < NULL_2023 || y * mid - x == NULL_2023) {
      result = mid;
      break;
    }
    if (y * mid < x) {
      low = mid;
    } else if (y * mid > x) {
      high = mid;
    }
  }
  if ((is_negative(lhs) && !is_negative(rhs)) || (!is_negative(lhs) && is_negative(rhs))) {
    return -result;
  }
  return result;
}

int2023_t& int2023_t::operator=(const int2023_t& other) {
  for (int i = 0; i < NUMS_SIZE; ++i) {
    this->nums[i] = other.nums[i];
  }
  return *this;
}

bool operator<(const int2023_t& lhs, const int2023_t& rhs) {
  if (is_negative(lhs) && !is_negative(rhs)) {
    return true;
  }
  if (!is_negative(lhs) && is_negative(rhs)) {
    return false;
  }
  if (is_negative(lhs) && is_negative(rhs)) {
    return absolute_value(lhs) > absolute_value(rhs);
  }
  for (int i = NUMS_SIZE - 1; i >= 0; --i) {
    if (lhs.nums[i] < rhs.nums[i]) {
      return true;
    } else if (lhs.nums[i] > rhs.nums[i]) {
      return false;
    }
  }
  return false;
}

bool operator>(const int2023_t& lhs, const int2023_t& rhs) {
  if (is_negative(lhs) && !is_negative(rhs)) {
    return false;
  }
  if (!is_negative(lhs) && is_negative(rhs)) {
    return true;
  }
  if (is_negative(lhs) && is_negative(rhs)) {
    return absolute_value(lhs) < absolute_value(rhs);
  }
  for (int i = NUMS_SIZE - 1; i >= 0; --i) {
    if (lhs.nums[i] > rhs.nums[i]) {
      return true;
    } else if (lhs.nums[i] < rhs.nums[i]) {
      return false;
    }
  }
  return false;
}

bool operator<=(const int2023_t& lhs, const int2023_t& rhs) {
  if (is_negative(lhs) && !is_negative(rhs)) {
    return true;
  }
  if (!is_negative(lhs) && is_negative(rhs)) {
    return false;
  }
  if (is_negative(lhs) && is_negative(rhs)) {
    return absolute_value(lhs) >= absolute_value(rhs);
  }
  for (int i = NUMS_SIZE - 1; i >= 0; --i) {
    if (lhs.nums[i] < rhs.nums[i]) {
      return true;
    } else if (lhs.nums[i] > rhs.nums[i]) {
      return false;
    }
  }
  return true;
}

bool operator>=(const int2023_t& lhs, const int2023_t& rhs) {
  if (is_negative(lhs) && !is_negative(rhs)) {
    return false;
  }
  if (!is_negative(lhs) && is_negative(rhs)) {
    return true;
  }
  if (is_negative(lhs) && is_negative(rhs)) {
    return absolute_value(lhs) <= absolute_value(rhs);
  }
  for (int i = NUMS_SIZE - 1; i >= 0; --i) {
    if (lhs.nums[i] > rhs.nums[i]) {
      return true;
    } else if (lhs.nums[i] < rhs.nums[i]) {
      return false;
    }
  }
  return true;
}

bool operator==(const int2023_t& lhs, const int2023_t& rhs) {
  for (int i = 0; i < NUMS_SIZE; ++i) {
    if (lhs.nums[i] != rhs.nums[i]) {
      return false;
    }
  }
  return true;
}

bool operator!=(const int2023_t& lhs, const int2023_t& rhs) {
  for (int i = 0; i < NUMS_SIZE; ++i) {
    if (lhs.nums[i] != rhs.nums[i]) {
      return true;
    }
  }
  return false;
}

std::ostream& operator<<(std::ostream& stream, const int2023_t& value) {
  int2023_t tmp = value;
  if (is_negative(tmp)) {
    stream << '-';
    tmp = absolute_value(value);
  }
  for (int i = NUMS_SIZE - 1; i >= 0; --i) {
    stream << (int)tmp.nums[i] << ' ';
  }
  return stream;
}