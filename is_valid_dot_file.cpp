#include "is_valid_dot_file.h"

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "fileio.h"
#include "save_graph_to_dot.h"

bool is_valid_dot_file(const std::string& dot_filename) noexcept
{
  const ribi::FileIo f;
  if (!f.IsRegularFile(dot_filename)) { return false; }
  const auto v = f.FileToVector(dot_filename);
  if (v.size() <= 1) return false;
  assert(!v.back().empty());
  return v.back()[0] == '}';
}

void is_valid_dot_file_test() noexcept
{
  //An empty undirected graph should be convertable to a valid .dot file
  {
    const auto g = create_empty_undirected_graph();
    const std::string filename{
      "is_valid_dot_file_test_create_empty_undirected_graph.dot"
    };
    save_graph_to_dot(g,filename);
    assert(is_valid_dot_file(filename));
  }
  //An empty directed graph should be convertable to a valid .dot file
  {
    const auto g = create_empty_directed_graph();
    const std::string filename{
      "is_valid_dot_file_test_create_empty_directed_graph.dot"
    };
    save_graph_to_dot(g,filename);
    assert(is_valid_dot_file(filename));
  }
  //A K2 graph should be convertable to a valid .dot file
  {
    const auto g = create_k2_graph();
    const std::string filename{
      "is_valid_dot_file_test_create_k2_graph.dot"
    };
    save_graph_to_dot(g,filename);
    assert(is_valid_dot_file(filename));
  }
  std::cout << __func__ << ": OK" << '\n';
}