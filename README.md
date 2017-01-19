Card Checker
============

A payment/credit card number checker. A C++ library.

Given a card number, identifies issuer (e.g. Visa or MasterCard or etc) and runs checksum (i.e. Luhn test).


## HOW TO BUILD

./bootstrap && ./configure && make


## HOW TO RUN

Run self-tests:
make check

Run example:
./src/main


## ENVIRONMENT

Tested under:
* Mac OS Sierra
* Xcode 8.2.1
* Homebrew 1.1.6
	* autoconf: stable 2.69 (bottled)
	* autoconf-archive: stable 2016.09.16 (bottled)
	* automake: stable 1.15 (bottled)
	* boost: stable 1.63.0 (bottled), HEAD
	* gcc: stable 6.3.0 (bottled), HEAD
	* pkg-config: stable 0.29.1 (bottled)
* Uses C++11 features.


## LICENSE

Copyright 2017 Rick Lan

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
