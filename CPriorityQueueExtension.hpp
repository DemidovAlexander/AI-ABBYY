//
//  CPriorityQueueExtension.hpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 25/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#ifndef CPriorityQueueExtension_h
#define CPriorityQueueExtension_h

#include <queue>
#include <vector>

template<
    class T,
    class Container = std::vector< T >,
    class Compare = std::less< typename Container::value_type >
    > class PriorityQueueExtension : public std::priority_queue< T, Container, Compare >
{
public:
    typedef typename
    std::priority_queue<
        T,
        Container,
        Compare >::container_type::const_iterator const_iterator;
    
    const_iterator find(const T&val) const {
        auto first = this->c.cbegin();
        auto last = this->c.cend();
        while (first!=last) {
            if (*first==val) {
                return first;
            }
            ++first;
        }
        return last;
    }
    
    const_iterator end() const {
        auto last = this->c.cend();
        return last;
    }
};

#endif /* CPriorityQueueExtension_h */
