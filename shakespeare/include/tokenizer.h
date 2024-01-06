#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "sentence.h"
#include "token.h"

namespace shakespeare
{
    class Tokenizer
    {
    public:
        Tokenizer();
        void Train
        (
            const std::vector<Sentence>& corpus,
            size_t vocab_size
        );
        std::vector<Token> Tokenize(const Sentence& input);
        void SaveModel(const std::string& filename);
        void LoadModel(const std::string& filename);
    private:
        std::unordered_map<Token, int> vocab_;
        void InitVocab(const std::vector<Sentence>& corpus);
        std::pair<Token, Token> FindMostFrequentPair
        (
            const std::vector<Sentence>& corpus
        );
        void UpdateVocab(const Token& new_token);
        void ReplaceMostFrequentPair
        (
            std::vector<Sentence>& corpus,
            const std::pair<Token, Token>& pair,
            const Token& new_token
        );
    };
}

#endif
