/*
stores and manages corpus vocabulary
*/

#include <limits>
#include "vocabulary.h"

namespace shakespeare
{
    Vocabulary::Vocabulary() : count_(0), index_counter_(0)
    {

    }
    // ------------------------------------------------------------------------
    Vocabulary::~Vocabulary()
    {

    }
    // ------------------------------------------------------------------------
    void Vocabulary::AddToken(const std::wstring& token)
    {
        auto iter = token_2_index_.find(token);
        if (iter == token_2_index_.end())
        {
            token_2_index_[token] = index_counter_;
            index_2_token_[index_counter_] = token;
            token_2_freq_[token] = 1;
	    ++index_counter_;
	    ++count_;
        }
        else
        {
            ++token_2_freq_[token];
        }
    }
    // ------------------------------------------------------------------------
    void Vocabulary::MergeTokens(const std::wstring& left,
                                 const std::wstring& right,
                                 size_t frequency)
    {
        auto iter_left = token_2_index_.find(left);
        auto iter_right = token_2_index_.find(right);
        if (iter_left != token_2_index_.end() &&
            iter_right != token_2_index_.end())
        {
            std::wstring new_token = left + right;
	    token_2_index_[new_token] = index_counter_;
            index_2_token_[index_counter_] = new_token;
            token_2_freq_[new_token] = frequency;
            (token_2_freq_[left] -= frequency) == 0 ?
	        RemoveTokenInternal(left) : void();
            (token_2_freq_[right] -= frequency) == 0 ?
		RemoveTokenInternal(right) : void();
	    ++index_counter_;
            ++count_;
        }
    }
    // ------------------------------------------------------------------------
    void Vocabulary::RemoveToken(const std::wstring& token)
    {
	RemoveTokenInternal(token);
    }
    // ------------------------------------------------------------------------
    size_t Vocabulary::GetTokenIndex(const std::wstring& token) const
    {
	auto iter = token_2_index_.find(token);
        return (iter != token_2_index_.end()) ?
	    iter->second : std::numeric_limits<size_t>::max();
    }
    // ------------------------------------------------------------------------
    std::wstring Vocabulary::GetIndexToken(size_t index) const
    {
	auto iter = index_2_token_.find(index);
        return (iter != index_2_token_.end()) ?
            iter->second : L"";
    }
    // ------------------------------------------------------------------------
    size_t Vocabulary::GetTokenFrequency(const std::wstring& token) const
    {
	auto iter = token_2_freq_.find(token);
        return (iter != token_2_freq_.end()) ?
	    iter->second : std::numeric_limits<size_t>::max();
    }
    // ------------------------------------------------------------------------
    size_t Vocabulary::GetCount() const
    {
	return count_;
    }
    // ------------------------------------------------------------------------
    void Vocabulary::RemoveTokenInternal(const std::wstring& token)
    {
	auto iter = token_2_index_.find(token);
	if (iter != token_2_index_.end())
        {
            size_t index = iter->second;
	    token_2_index_.erase(token);
	    index_2_token_.erase(index);
	    token_2_freq_.erase(token);
	    --count_;
        }
    }
} // namespace shakespeare
