#pragma once

#include <string>
#include <fstream>
#include <iostream>

struct MyCout
{
  /// ������� ������
  MyCout& operator << (const std::string &cmd)
  {
    std::cout << cmd;
    return *this;
  }
};


struct MyFile
{      
  /// �����������
  /// @param time_str ����� � ���� ������
  explicit MyFile(std::string time_str)
  {
    std::string name = std::string("bulk") + time_str + std::string(".log");
    file.open(name);
  }
  /// ����������
  ~MyFile()
  {
    file.close();
  }
  /// ������� ������
  MyFile& operator << (const std::string &cmd)
  {
    file << cmd;
    return *this;
  }

private:
  std::ofstream file;
};