/*
 * Copyright (c) 2008, detrox@gmail.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY detrox@gmail.com ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL {detrox,weibingzheng}@gmail.com BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef PREPARE_PROCESSOR_HXX
#define PREPARE_PROCESSOR_HXX

#include "processor.hxx"
#include "ilexicon.hxx"
#include "datrie.hxx"
#include "utf8.hxx"

#define MAX_TOKEN_BUFFER 512

namespace bamboo {


class PrepareProcessor: public Processor {
protected:
	PrepareProcessor();
	bool _can_process(TokenImpl *token)
	{
		return (token->get_attr() == TokenImpl::attr_unknow);
	}
	void _process(TokenImpl *token, std::vector<TokenImpl *> &out);
	int _characterize;
	int _concat;
public:
	PrepareProcessor(IConfig *config);
	~PrepareProcessor() {};
	static const char *get_crf2_tag(const TokenImpl *token) {
		switch(token->get_attr()) {
		case TokenImpl::attr_number:
		case TokenImpl::attr_alpha:
			return "ASCII";
		case TokenImpl::attr_punct:
			return "PUNC";
		case TokenImpl::attr_cword:
			return "CN";
		default:
			return "CN";
		}
	}
};

} //namespace bamboo

#endif // PREPARE_PROCESSOR_HXX
