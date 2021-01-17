// Copyright 2021 Roger Peralta Aranibar
#ifndef SOURCE_PERSISTENCE_PARTIAL_DIRECTED_GRAPH_HPP_
#define SOURCE_PERSISTENCE_PARTIAL_DIRECTED_GRAPH_HPP_
#include <utility>
namespace ADE {
    namespace Persistence {

/*
template<typename X,typename Y>
class qwerty{
public:
    unsigned int versionn;
    X* ptr,Y valorr,bool x,size_t i;
    //constructor
    qwerty(Y valor, int version){
        valorr(valor);
        versionn(version);
        x(false);
        ptr(NULL);}
    qwerty(size_t a, X* ptr1, unsigned int version) {
        ptr(ptr1);
        versionn(version);
        x(true);
        i(a);} };*/

template <typename Type>
//para la clase partial node uso herencia de la clase node
class PartialNode:public Node<Type> {
 public:
  typedef Type data_type;
  data_type* data_;
  std::size_t out_ptrs_size_;
  PartialNode** forward_;
  std::size_t in_ptrs_size_;
  std::vector<qwerty<datatype>*>vector_De_mod;
  std::size_t current_modifications_size_;
  std::size_t current_back_pointer_size_;
  PartialNode** backward_;
  PartialNode() {}
  PartialNode(data_type const& data, std::size_t const& out_ptrs_size,
              std::size_t const& in_ptrs_size) {
    backward_ = new PartialNode<Type>*[in_ptrs_size]();}

  data_type get_data(unsigned int version){
      return *Node<Type>::data_;
  }
  bool dar_puntero(PartialNode* puntero1, unisgned int x) {
      Node<type>::forward_ = puntero1;
      return true;
  }

  bool set_data(data_type const& data) { return true; }
  PartialNode* insert_vertex(std::size_t const& position,
                             data_type const& data) {
    return nullptr;}
  bool update_edge(std::size_t const& position, PartialNode* v) {
      return true; 
  }
  
  PartialNode& operator[](
      std::pair<std::size_t, unsigned int> id_version) const {
      return *dynamic_cast<PartialNode*>(
          &(Node<Type>::operator[](id_version.first)));
  }

};
template <typename Type, typename Node=PartialNode<Type, Node>>
//para la clase partial node uso herencia de la clase DirectedGraph
class PartialDirectedGraph:public DirectedGraph<Type,Node> {
 public:
  typedef Type data_type;

  PartialDirectedGraph(data_type const data, std::size_t const& out_ptrs_size,
      std::size_t const& in_ptrs_size) {
      DirectedGraph<Type, Node>(data, out_ptrs_size);
      in_ptrs_size_(in_ptrs_size);
  }

  Node* get_root_ptr(unsigned int const& version) { return nullptr; }
  Node get_root(unsigned int const& version) { return; }
  bool add_edge(Node* u, Node* v, std::size_t position) {++(*current_version_);
    return true;}
 protected:
  unsigned int* current_version_;
  std::size_t in_ptrs_size_;
  Node* root_ptr_;
  std::size_t out_ptrs_size_;
  Node* insertar(data_type const data, Node* u, std::size_t position, unsigned int version) {
      return DirectedGraph<Type, Node>::insertar(data, u, position);
  }
};

}  // namespace Persistence
}  // namespace ADE

#endif  // SOURCE_PERSISTENCE_PARTIAL_DIRECTED_GRAPH_HPP_
