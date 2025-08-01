# Controller Tester
Quick-and-dirty SFML application for showing the status of the first game controller attached to the system.

![Screen shot](https://www.martyndavis.com/wp-content/uploads/2024/07/controller_tester.png "")


### Requirements

**libfmt** (using fmt::format as Raspberry Pi's g++ at the time of writing doesn't support `std::format`)

Assuming you have a working clang++, the only other requirement is SFML **3**. For mac,
install with Homebrew (assuming you have that installed): `brew install sfml`
At the time of writing, SFML 3.x needs to be manually built and installed on a Raspberry Pi as the
apt repos still only contain SFML 2.6.x.
