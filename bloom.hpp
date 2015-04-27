/*
 *********************************************************************
 *                                                                   *
 *                           Bloom Filter                      	     *
 *                                                                   *
 * Author: Mateusz Matejuk                                           *
 * https://plus.google.com/+MateuszMatejuk/posts                     *
 * WORK IN PROGRESS!						     *
 *********************************************************************
*/


#ifndef INCLUDE_CPP_ESV_BLOOMF_HPP
#ifndef INCLUDE_CPP_ESV_BLOOMF_HPP

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iterator>
#include <limits>
#include <string>
#include <vector>
#include <functional>
#include <openssl/sha.h>
#include <stdint>
#include <cstdlib>


// bloom internal return type
// TODO no defines!
class BIRT
{
	inline unsigned char OK			();
	inline unsigned char ERROR		();
};


// bloom internal type storage
template<typename T>
class BITS
{
    public:
	BIRT hashme (const char * input, uint64_t size)
	{
	    unsigned char digest[SHA512_DIGEST_LENGTH];
	    SHA512_CTX ctx;
	    SHA512_Init(&ctx);
	    SHA512_Update(&ctx, input, size);
	    SHA512_Final(digest, &ctx);
	    std::memcpy(ctx, this->block, 64)
	}

	BITS()
	{
	    this->block = malloc(64);
	};
	BITS( T & what, uint64_t size_in_bytes)
	{
	    this->block = malloc(64);
	    hashme(what, size_in_bytes);
	};
	~BITS();

    private:
	T type;
	void * block;
}

class bloom
{
    public:
	bloom();
	~bloom();
	void * block;
	BIRT cipher();
	BIRT check();
	BIRT insert();
};

