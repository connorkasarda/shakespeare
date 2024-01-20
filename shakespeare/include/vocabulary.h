/*
Maintains corpus vocabulary
*/

#ifndef VOCABULARY_H
#define VOCABULARY_H

#include <unordered_map>
#include <string>
#include <atomic>

namespace shakespeare
{
    /** stores and maintains corpus vocabulary */
    class Vocabulary
    {
    public:
        /** constructor */
        Vocabulary();

        /** destructor */
        ~Vocabulary();

        /** function to add a new token
	@param token The token to add to the vocab
	*/
        void AddToken(const std::wstring& token);

	/** function to merge two tokens
	@param left Leftside token in merge
	@param right Rightside token in merge
	@param frequency Frequency of token pair found by model
	*/
        void MergeTokens(const std::wstring& left,
	                 const std::wstring& right,
                         size_t frequency);

        /** function to remove token
	@param token The token to remove from the vocab
	*/
        void RemoveToken(const std::wstring& token);

	/** function to return token's index
	@param token The token we want the index of
	*/
	size_t GetTokenIndex(const std::wstring& token) const;

	/** function to return index's token
	@param index The index we want the token of
	*/
	std::wstring GetIndexToken(size_t index) const;

	/** function to return token's frequency
	@param token The token we want the frequency of
	*/
	size_t GetTokenFrequency(const std::wstring& token) const;

	/** function to get vocabulary count */
        size_t GetCount() const;
    private:
        /** mapping of token to index */
        std::unordered_map<std::wstring, size_t> token_2_index_;

        /** mapping of index to token */
        std::unordered_map<size_t, std::wstring> index_2_token_;

        /** mapping of token to frequency */
        std::unordered_map<std::wstring, size_t> token_2_freq_;

        /** number of tokens in vocabulary */
        size_t count_;

	/** atomic index counter for token index assignments */
	std::atomic_size_t index_counter_;

	/** internal token removal function
	@param token The token to remove from vocab
	*/
	void RemoveTokenInternal(const std::wstring& token);
    }; // class Vocabulary
} // namespace shakespeare

#endif
