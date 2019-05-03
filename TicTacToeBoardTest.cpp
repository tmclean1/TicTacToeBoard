/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST( TicTacToeBoardTest, getpieceBlank)
{
	TicTacToeBoard myboard;
	ASSERT_TRUE(myboard.getPiece(0,0) == Blank);
}

TEST( TicTacToeBoardTest, getpieceInvalidoverMax)
{
	TicTacToeBoard myboard;
	ASSERT_TRUE(myboard.getPiece(4,4) == Invalid);
}

TEST( TicTacToeBoardTest, getpieceInvalidUnderMin)
{
	TicTacToeBoard myboard;
	ASSERT_TRUE(myboard.getPiece(-1,-1) == Invalid);
}

TEST( TicTacToeBoardTest, placingPieceReplacesBlank)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	ASSERT_TRUE(myboard.getPiece(0,0) != Blank);
}


TEST( TicTacToeBoardTest, placingPieceInvalidoverMax)
{
	TicTacToeBoard myboard;
	ASSERT_TRUE(myboard.placePiece(4,4) == Invalid);
}

TEST( TicTacToeBoardTest, placingPieceInvalidUnderMin)
{
	TicTacToeBoard myboard;
	ASSERT_TRUE(myboard.placePiece(-2,-2) == Invalid);
}

TEST( TicTacToeBoardTest, placingPieceInvalidUnderMinRowOverMaxColumn)
{
	TicTacToeBoard myboard;
	ASSERT_TRUE(myboard.placePiece(-2, 5) == Invalid);
}

TEST( TicTacToeBoardTest, placingPieceInvalidUnderMinColumnOverMaxRow)
{
	TicTacToeBoard myboard;
	ASSERT_TRUE(myboard.placePiece(7 ,-2) == Invalid);
}

TEST( TicTacToeBoardTest, placingPieceInvalidRowOverMaxColumnInRange)
{
	TicTacToeBoard myboard;
	ASSERT_TRUE(myboard.placePiece(7 , 2) == Invalid);
}

TEST( TicTacToeBoardTest, placingPieceInvalidRowInRangeColumnUnderMin)
{
	TicTacToeBoard myboard;
	ASSERT_TRUE(myboard.placePiece(2 ,-2) == Invalid);
}

TEST( TicTacToeBoardTest, placingPieceInvalidColumnOverMaxRowInRange)
{
	TicTacToeBoard myboard;
	ASSERT_TRUE(myboard.placePiece(2 , 7) == Invalid);
}

TEST( TicTacToeBoardTest, placingPieceInvalidRowUnderMinColumnInRange)
{
	TicTacToeBoard myboard;
	ASSERT_TRUE(myboard.placePiece(-2 , 2) == Invalid);
}


TEST( TicTacToeBoardTest, togglesfromX)
{
	TicTacToeBoard myboard;
	myboard.toggleTurn();
	myboard.placePiece(0, 0);
	ASSERT_TRUE(myboard.getPiece(0,0) == O);
}


TEST( TicTacToeBoardTest, togglesfromO)
{
	TicTacToeBoard myboard;
	myboard.toggleTurn();
	myboard.toggleTurn();
	myboard.placePiece(1, 1);
	ASSERT_TRUE(myboard.getPiece(1,1) == X);
}


TEST( TicTacToeBoardTest, placingPieceOverExistingPiece)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	ASSERT_TRUE(myboard.placePiece(0,0) == X);
}


TEST( TicTacToeBoardTest, placingPieceTogglesPiece)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	myboard.placePiece(1,1);
	ASSERT_TRUE(myboard.getPiece(1,1) == O);
}


TEST( TicTacToeBoardTest, winnerInvalidIfboardEmpty)
{
	TicTacToeBoard myboard;
	ASSERT_TRUE(myboard.getWinner() == Invalid);
}

TEST( TicTacToeBoardTest, WinnerInvalidIfBoardNotFull)
{
	TicTacToeBoard myboard;
	myboard.placePiece(1,1);
	myboard.placePiece(1,2);
	myboard.placePiece(0,1);
	myboard.placePiece(1,0);
	myboard.placePiece(2,1);
	myboard.placePiece(2,0);
	myboard.placePiece(0,0);
	myboard.placePiece(0,2);
	ASSERT_TRUE(myboard.getWinner() == Invalid);
}


TEST( TicTacToeBoardTest, XWinsDiagonalRight)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	myboard.placePiece(1,0);
	myboard.placePiece(2,0);
	myboard.placePiece(0,1);
	myboard.placePiece(1,1);
	myboard.placePiece(2,1);
	myboard.placePiece(0,2);
	myboard.placePiece(2,2);
	myboard.placePiece(1,2);
	ASSERT_TRUE(myboard.getWinner() == X);
}

TEST( TicTacToeBoardTest, OWinsDiagonalRight)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	myboard.placePiece(1,1);
	myboard.placePiece(2,2);
	myboard.placePiece(2,0);
	myboard.placePiece(1,0);
	myboard.placePiece(0,1);
	myboard.placePiece(1,2);
	myboard.placePiece(0,2);
	myboard.placePiece(2,1);
	ASSERT_TRUE(myboard.getWinner() == O);
}

TEST( TicTacToeBoardTest, NoWinners)
{
	TicTacToeBoard myboard;
	myboard.placePiece(1,1);
	myboard.placePiece(2,0);
	myboard.placePiece(0,0);
	myboard.placePiece(1,0);
	myboard.placePiece(0,2);
	myboard.placePiece(0,1);
	myboard.placePiece(1,2);
	myboard.placePiece(2,2);
	myboard.placePiece(2,1);
	ASSERT_TRUE(myboard.getWinner() == Blank);
}

TEST( TicTacToeBoardTest, XWinsHorizontllyTop)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	myboard.placePiece(0,1);
	myboard.placePiece(1,0);
	myboard.placePiece(1,1);
	myboard.placePiece(2,0);
	myboard.placePiece(2,2);
	myboard.placePiece(0,2);
	myboard.placePiece(1,2);
	myboard.placePiece(2,1);
	ASSERT_TRUE(myboard.getWinner() == X);
}

TEST( TicTacToeBoardTest, XWinsHorizontllyMiddle)
{
	TicTacToeBoard myboard;
	myboard.placePiece(1,1);
	myboard.placePiece(1,0);
	myboard.placePiece(2,0);
	myboard.placePiece(0,2);
	myboard.placePiece(0,1);
	myboard.placePiece(2,2);
	myboard.placePiece(1,2);
	myboard.placePiece(0,0);
	myboard.placePiece(2,1);
	ASSERT_TRUE(myboard.getWinner() == X);
}

TEST( TicTacToeBoardTest, XWinsHorizontllyBottom)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,2);
	myboard.placePiece(1,1);
	myboard.placePiece(1,2);
	myboard.placePiece(0,0);
	myboard.placePiece(2,2);
	myboard.placePiece(2,0);
	myboard.placePiece(1,0);
	myboard.placePiece(0,1);
	myboard.placePiece(2,1);
	ASSERT_TRUE(myboard.getWinner() == X);
}

TEST( TicTacToeBoardTest, XWinsDiagonallyLeft)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	myboard.placePiece(0,2);
	myboard.placePiece(1,1);
	myboard.placePiece(1,0);
	myboard.placePiece(2,1);
	myboard.placePiece(0,1);
	myboard.placePiece(2,0);
	myboard.placePiece(1,2);
	myboard.placePiece(2,2);
	ASSERT_TRUE(myboard.getWinner() == X);
}

TEST( TicTacToeBoardTest, OWinsDiagonalLeft)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,1);
	myboard.placePiece(0,0);
	myboard.placePiece(1,2);
	myboard.placePiece(1,0);
	myboard.placePiece(1,1);
	myboard.placePiece(2,1);
	myboard.placePiece(2,0);
	myboard.placePiece(0,2);
	myboard.placePiece(2,2);
	ASSERT_FALSE(myboard.getWinner() == O);
}

TEST( TicTacToeBoardTest, XWinsVerticallyLeft)
{
	TicTacToeBoard myboard;
	myboard.placePiece(0,0);
	myboard.placePiece(2,0);
	myboard.placePiece(0,1);
	myboard.placePiece(2,1);
	myboard.placePiece(2,2);
	myboard.placePiece(1,1);
	myboard.placePiece(1,0);
	myboard.placePiece(1,2);
	myboard.placePiece(0,2);
	ASSERT_TRUE(myboard.getWinner() == X);
}

TEST( TicTacToeBoardTest, XWinsVerticallyMiddle)
{
	TicTacToeBoard myboard;
	myboard.placePiece(1,0);
	myboard.placePiece(0,0);
	myboard.placePiece(1,1);
	myboard.placePiece(0,1);
	myboard.placePiece(0,2);
	myboard.placePiece(2,2);
	myboard.placePiece(2,1);
	myboard.placePiece(2,0);
	myboard.placePiece(1,2);
	ASSERT_TRUE(myboard.getWinner() == X);
}

TEST( TicTacToeBoardTest, XWinsVerticallyRight)
{
	TicTacToeBoard myboard;
	myboard.placePiece(2,0);
	myboard.placePiece(1,0);
	myboard.placePiece(2,1);
	myboard.placePiece(0,2);
	myboard.placePiece(1,2);
	myboard.placePiece(0,0);
	myboard.placePiece(0,1);
	myboard.placePiece(1,1);
	myboard.placePiece(2,2);
	ASSERT_TRUE(myboard.getWinner() == X);
}