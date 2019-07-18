#pragma once

template <typename Node>
class TestTemplate{
public:

  TestTemplate(Node node):
  data(node) { }

  Node data;

  void print();
};

