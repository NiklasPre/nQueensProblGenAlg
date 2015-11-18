//Not tested

#include <iostream>
#include <stdlib.h>

/*
 * Class defines Population for the algorithm;
 * template parameter N sets n in n-Queens Problem
 */
template <size_t N>
class Population {

  /*
   * Indiviual of the Population
   * m_iFitnness - Integer that represents the viability to use in Mutation/Crossover
   * m_rgQueenPositions - Integer Array with positions of Queens
   */
  struct ChessBoard {
    int m_iFitness;
    int m_rgQueenPositions[N-1];

    /*
     * Constructor - Randomizes position of queens
     */
    ChessBoard() {
      m_iFitness = 0;
      for(int i = 0; i < N; i++) {
        m_rgQueenPositions[i] = rand() % N;
      }
    }

    /*
     * Function to set the fitness var
     */
    void fnCheckFitness() {
      m_iFitness -= fnCheckRow() + fnCheckDiag();
    }

    int fnCheckRow();
    int fnCheckDiag(); // TODO: combine with fnCheckRow; OR use Threads?
    //TODO: Destructor

  };

  /*
   * Dynamic array that holds the Indiviuals (TODO: use vector instead?)
   */
  ChessBoard **m_rgcbPopulation;

public:
  Population();
  void fnRateFitness();
  virtual std::ostream& print(std::ostream& o) const;

/*
 * Constructor - Fills member Array with 50 Individuals (TODO: 50?!)
 */


};

template <size_t N>
Population<N>::Population() {
  for(int i = 0; i < 50; i++) {
    m_rgcbPopulation[i] = new ChessBoard();
  }
}

template <size_t N>
void Population<N>::fnRateFitness() {
  for(int i = 0; i < 50; i++) {
    m_rgcbPopulation[i]->fnCheckFitness();
  }

}

/*
 * Checks if a queen is the only one in a vertical/horizontal row
 * counter to modify fitness var in Individuals
 */
template <size_t N>
int Population<N>::ChessBoard::fnCheckRow() {
  int i_cFitCountRow;

  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N-i; j++) { //TODO: if i == N / Array out of bound
      if(m_rgQueenPositions[i] == m_rgQueenPositions[j]) {
        i_cFitCountRow++;
      }
    }
  }

return i_cFitCountRow;
}

/*
 * Checks if a queen is the only one in a diagonal row
 * counter to modify fitness var in Individuals
 */
template <size_t N>
int Population<N>::ChessBoard::fnCheckDiag() {
  int i_cFitCountDiag;

  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N-i; j++) {
      if(m_rgQueenPositions[j] == m_rgQueenPositions[i]+j || m_rgQueenPositions[j] == m_rgQueenPositions[i]-j) {
        i_cFitCountDiag++;
      }

    }
  }



  return i_cFitCountDiag;
}

template<size_t N>
std::ostream& Population<N>::print(std::ostream& o) const {
  o << "Population, N= " << N << '\n';
  for(int i = 0; i < 10; i++) {
    o << "Individual " << i << ": " << '\n';
    for(int j = 0; j < 5; j++) {
      o << "QueensPos: [" << m_rgcbPopulation[i]->m_rgQueenPositions[j] << ' ' << '\n';
    } o << ']' << '\n';
  }

  return o;
}
