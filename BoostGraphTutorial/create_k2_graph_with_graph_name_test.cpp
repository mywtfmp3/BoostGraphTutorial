#include "create_k2_graph_with_graph_name.h"
#include "create_k2_graph_with_graph_name_demo.impl"

#include <boost/test/unit_test.hpp>
#include "copy_file.h"
#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_vertex_descriptors.h"
#include "get_edge_descriptors.h"
#include "save_graph_with_graph_name_to_dot.h"
#include "convert_dot_to_svg.h"
#include "is_regular_file.h"

BOOST_AUTO_TEST_CASE(create_k2_graph_with_graph_name_thorough)
{
  //Basic tests
  {
    const auto g = create_k2_graph_with_graph_name();
    const auto vip = get_vertex_iterators(g);
    BOOST_CHECK(vip.first != vip.second);
    const auto vds = get_vertex_descriptors(g);
    BOOST_CHECK(vds.size() == 2);
    const auto eip = get_edge_iterators(g);
    BOOST_CHECK(eip.first != eip.second);
    const auto eds = get_edge_descriptors(g);
    BOOST_CHECK(eds.size() == 1);
    BOOST_CHECK(boost::num_edges(g) == 1);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(get_graph_name(g) == "K2");
  }
  //Create the .dot and .svg of the 'create_k2_graph_with_graph_name' chapter
  {

    const auto g = create_k2_graph_with_graph_name();
    const std::string base_filename{"create_k2_graph_with_graph_name"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_graph_with_graph_name_to_dot(g,dot_filename);
    BOOST_CHECK(is_regular_file(dot_filename));
    convert_dot_to_svg(dot_filename,svg_filename);
    BOOST_CHECK(is_regular_file(svg_filename));
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );

  }
}