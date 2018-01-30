
#include "rtos.h"
#include "dummy.h"
/*
#include "gtest/gtest.h"

namespace {
	class frameworkTest : public ::testing::Test {
	 	protected:
	   		frameworkTest() : dummy_board(&board_data) { }
	  		virtual ~frameworkTest() { }
	  		virtual void SetUp() { }
	  		virtual void TearDown() { }
			rtos dummy_board;
	};

	uint32_t forward_mask(uint32_t in, uint32_t i) {
		return (in & ~(1 << i));
	}

	uint32_t reverse_mask(uint32_t in, uint32_t i) {
		return (in & ~(1 << (31 - i)));
	}

	TEST_F(frameworkTest, framework) {
		uint32_t i = 0;
		dummy_board.update_stack();
		for(auto& d : *dummy_board.dum_list) {
			EXPECT_EQ((*d).host_val, forward_mask(0xFFFFFFFF, i));
			EXPECT_EQ((*d).drv_val, reverse_mask(forward_mask(0xFFFFFFFF, i), i));
			i++;
		}
	}

}  // namespace

int main(int argc, char **argv) {
  	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}
*/

rtos<drivers>* dummy_board;

int main(int argc, char **argv) {
	// disable interrupts
	dummy_board = new rtos<drivers>(board_drivers, &board_mappings);
	// enable interrupts
	dummy_board->update_stack();
}
