#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>

#define bnuc boost::numeric::ublas

class sparseMatrix
{
public:
    sparseMatrix(const std::size_t _size1, const std::size_t _size2) : size1(_size1), size2(_size2), m(size1, size2, )
    {

    }


private:
    size_t size1;
    size_t size2;
    bnuc::coordinate_matrix<double> m;
};

int main()
{
    using namespace boost::numeric::ublas;
    coordinate_matrix<double> m(10, 10, 40);
    m(5, 5) = 2;
    std::cout << m.nnz() << std::endl;
}