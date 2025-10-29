#pragma once

template<typename T, typename Cont>
typename MutantStack<T, Cont>::iterator MutantStack<T, Cont>::begin() {
	return this->c.begin(); 
}

template<typename T, typename Cont>
typename MutantStack<T, Cont>::iterator MutantStack<T, Cont>::end() {
	return this->c.end(); 
}

template<typename T, typename Cont>
typename MutantStack<T, Cont>::const_iterator MutantStack<T, Cont>::begin() const {
	return this->c.begin(); 
}

template<typename T, typename Cont>
typename MutantStack<T, Cont>::const_iterator MutantStack<T, Cont>::end() const {
	return this->c.end(); 
}
