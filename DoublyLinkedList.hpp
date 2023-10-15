#ifndef MY_DOUBLY_LINKED_LIST_HPP
#define MY_DOUBLY_LINKED_LIST_HPP


/**
 * TODO: Implement DoublyLinkedList, its Node, and its Iterator!
 * 
 * I've left some methods filled out for you,
 * 	and stubbed out some structure, to reduce difficulty.
 * 
 * You may add or remove methods as you see fit,
 * 	as long as you can still pass all unit tests.
 * Although, it may be more difficult to do so. Your choice!
 * 
 * Notice we're inside a namespace here.
 * The DLL is inside a namespace called DoublyLinkedList,
 * 	which is itself inside a namespace called CPSC131
 * This means, if you'd like to play around with your class later,
 * 	you'll need to access it like so:
 * ::CPSC131::DoublyLinkedList::DoublyLinkedList<int> list;
 * 
 * Look into main.cpp and CPP_Tests.cpp for examples of using
 * 	the DLL and your BookStore. But don't worry too much, as you
 * 	only need to implement these classes
 * (main and tests are already done for you)
 */


//
#include <iostream>
#include <stdlib.h>
#include <stdexcept>


/**
 * Namespace for our classroom !
 */
namespace CPSC131
{
	/**
	 * Namespace to hold all things related to our DLL
	 */
	namespace DoublyLinkedList
	{
		/**
		 * Implement our DoublyLinkedList class !
		 */
		template <class T>
		class DoublyLinkedList
		{
			public:
				
				/**
				 * Node class, representing a single item in our linked list
				 */
				// TODO: Complete all class methods
				class Node
				{
					public:
						
						/// CTORS
						Node() : prev_(nullptr), next_(nullptr) {}
						Node(T element)
						{
							 elements_ = element;
						}
						Node(T element, Node* prev, Node* next) 
						{
							prev_ = prev;
							next_ = next;
							element_ = element;
						}
						
						/// Set the pointer to the previous element
						void setPrevious(Node* prev)
						{
							prev_ = prev;
						}
						
						/// Set the pointer to the previous element
						void setPrev(Node* prev)
						{
							prev_ = prev;
						}
						
						/// Get a pointer to the previous element
						Node* getPrevious() { return prev_; }
						
						/// Get a pointer to the previous element
						Node* getPrev() { return prev_; }
						
						/// Set the pointer to the next node
						void setNext(Node* next)
						{
							next_ = next;
						}
						
						/// Get a pointer to the next node
						Node* getNext() { return next_; }
						
						/// Set the element this node holds
						void setElement(T element) 
						{
							element_ = element;
						}
						
						/// Get the element this node holds
						///	YOUR WELCOME
						T& getElement() { return this->element_; }
						
						/// Return a reference to the element
						///	YOUR WELCOME
						T& operator*() { return this->element_; }
						
					private:
						T element_;
						Node* prev_;
						Node* next_;
				};
				
				/**
				 * Nested Iterator class.
				 * This allows user code to refer to the Iterator's type as:
				 * 
				 * CPSC131::DoublyLinkedList::DoublyLinkedList<int>::Iterator
				 * 
				 * (as opposed to specifying the template argument two times)
				 */
				class Iterator
				{
					public:
						
						///	Constructor that does nothing; YOUR WELCOME
						Iterator()
						{
							/// yw
						}
						
						///	Constructor taking a head and tail pointer; YOUR WELCOME
						Iterator(Node* head, Node* tail) : head_(head), tail_(tail)
						{
							this->cursor_ = this->end();
						}
						
						///	Constructor taking a head, tail, and cursor pointer; YOUR WELCOME
						Iterator(Node* head, Node* tail, Node* cursor) : head_(head), tail_(tail), cursor_(cursor) {}
						
						///	Get a pointer to the head node, or end() if this list is empty
						Node* begin()
						{
							//	TODO: Your code here
							
							
							return this->head_;
						}
						
						///	Get a node pointer representing "end" (aka "depleted"). Probably want to just use nullptr.
						Node* end()
						{
							//	TODO: Your code here
							
							return this->tail_->next_;
						}
						
						///	Get the node to which this iterator is currently pointing
						Node* getCursor()
						{
							//	TODO: Your code here
							
							return this->cursor_;
						}
						
						/**
						 * Assignment operator
						 * Return a copy of this Iterator, after modification
						 */
						Iterator& operator=(const Iterator& other)
						{
							//	TODO: Your code here
							this->head_ = other.head_;
							this->tail_ = other.tail_;
							this->cursor_ = other.cursor_;
							
							return *this;
						}
						
						///	Comparison operator
						bool operator==(const Iterator& other)
						{
							//	TODO: Your code here
							if (this->head_ == other.head_ &&
							this->tail_ == other.tail_ &&
							this->cursor_ == other.cursor_)
							{
								return true
							}
							
							else
							{
								return false;
							}
						}
						///	Inequality comparison operator
						bool operator!=(const Iterator& other)
						{
							//	TODO: Your code here
							if (this == other)
							{
								return false;
							}
							
							else
							{
								return true;
							}
						}
						
						/**
						 * Prefix increment operator
						 * Return a copy of this Iterator, after modification
						 */
						Iterator& operator++()
						{
							//	TODO: Your code here
							this->cursor_ = this->cursor_->getNext();
							
							return *this;
						}
						
						/**
						 * Postfix increment
						 * Return a copy of this Iterator, BEFORE it was modified
						 */
						Iterator operator++(int)
						{
							//	TODO: Your code here
							Iterator cursor_2 = this->cursor_;
							this->cursor_ = this->cursor_->getNext();
							
							return *cursor_2;
						}
						
						/**
						 * Prefix decrement operator
						 * Return a copy of this Iterator, after modification
						 */
						Iterator& operator--()
						{
							//	TODO: Your code here
							this->cursor_ = this->cursor_->getPrev();
							
							return *this;
						}
						
						/**
						 * Postfix decrement operator
						 * Return a copy of this Iterator BEFORE it was modified
						 */
						Iterator operator--(int)
						{
							//	TODO: Your code here
							Iterator cursor_2 = this->cursor_;
							this->cursor_ = this->cursor_->getPrev();
							
							return *cursor_2;
						}
						
						/**
						 * AdditionAssignment operator
						 * Return a copy of the current iterator, after modification
						*/
						Iterator operator +=(size_t add)
						{
							//	TODO: Your code here
							for (size_t i = 0; i<add; ++i)
							{
								this->cursor_ = this->cursor_->getNext();
							}
							
							return *this;
						}
						/**
						 * SubtractionAssignment operator
						 * Return a copy of the current iterator, after modification
						 */
						Iterator operator -=(size_t add)
						{
							//	TODO: Your code here
							for (size_t i = 0; i<add; ++i)
							{
								this->cursor_ = this->cursor_->getPrev();
							}
							
							return *this;
						}
						
						/**
						 * AdditionAssignment operator, supporting positive or negative ints
						 */
						Iterator operator +=(int add)
						{
							//	TODO: Your code here
							if (add>=0)
							{
								for (int i = 0; i<add; ++i)
								{
								this->cursor_ = this->cursor_->getNext();
								}
							}
							else
							{
								for (int i = add; i<0; ++i)
								{
								this->cursor_ = this->cursor_->getNext();
								}
							}
							
							return *this;
						}
						
						/**
						 * SubtractionAssignment operator, supporting positive or negative ints
						 */
						Iterator operator -=(int subtract)
						{
							//	TODO: Your code here
							if (subtract>=0)
							{
								for (int i = 0; i<subtract; ++i)
								{
								this->cursor_ = this->cursor_->getPrev();
								}
							}
							else
							{
								for (int i = subtract; i<0; ++i)
								{
								this->cursor_ = this->cursor_->getPrev();
								}
							}
							
							
							return *this;
						}
						
						/**
						 * Dereference operator returns a reference to the ELEMENT contained with the current node
						 */
						T& operator*()
						{
							//	TODO: Your code here
							
							return this->cursor_->getElement();
						}
					
					private:
						
						/// Pointer to the head node
						Node* head_ = nullptr;
						
						/// Pointer to the tail node
						Node* tail_ = nullptr;
						
						/**
						 * Pointer to the cursor node.
						 * This is only one way of letting the iterator traverse the linked list.
						 * You can change to a different method if you wish (and can still pass unit tests)
						 */
						Node* cursor_ = nullptr;
					
					friend class DoublyLinkedList;
				};
				
				/// Your welcome
				DoublyLinkedList()
				{
					//	TODO: Your code here
					head_ = nullptr;
					tail_ = nullptr;
					size_ = 0;
				}
				
				///	Copy Constructor
				DoublyLinkedList(DoublyLinkedList& other)
				{
					//	TODO: Your code here
					this->head_ = other.head_;
					this->tail_ = other.tail_;
					this->size_ = 0;
				}
				
				/// DTOR
				~DoublyLinkedList()
				{
					//	TODO: Your code here
					while (size_ != 0)
					{
						Node* temp = head_;
						head_= head->getNext();
						delete temp;
						temp = nullptr;
						--size;
					}
				}
				
				/**
				 * Clear the list and assign the same value, count times.
				 * If count was 5, T was int, and value was 3,
				 * 	we'd end up with a list like {3, 3, 3, 3, 3}
				 */
				void assign(size_t count, const T& value)
				{
					//	TODO: Your code here
					clear();
					size_ = count;
					while (count!=0)
					{
						T* current = head_;
						current->setElement(value);
						current = current->getNext();
						--count;
					}
				}
				
				/**
				 * Clear the list and assign values from another list.
				 * The 'first' iterator points to the first item copied from the other list.
				 * The 'last' iterator points to the last item copied from the other list.
				 * 
				 * Example:
				 * 	Suppose we have a source list like {8, 4, 3, 2, 7, 1}
				 * 	Suppose first points to the 4
				 *	Suppose last points to the 7
				 * 	We should end up with our list becoming: {4, 3, 2, 7}
				 *
				 * If the user code sends out-of-order iterators,
				 * 	just copy from 'first' to the end of the source list
				 * Example: first=7, last=4 from the list above would give us:
				 * 	{7, 1}
				 */
				void assign(Iterator first, Iterator last)
				{
					//	TODO: Your code here
					clear();
					Node* current = head_;
					
					while (first != last)
					{
					current->setElement(first.cursor_->getElement());
					current = current->getnext();
					++first;
				}
				
				/// Return a pointer to the head node, if any
				Node* head() const
				{
					//	TODO: Your code here
					
					return head_;
				}
				
				/// Return a pointer to the tail node, if any
				Node* tail() const
				{
					//	TODO: Your code here
					
					return tail_;
				}
				
				/**
				 * Return an iterator that points to the head of our list
				 */
				Iterator begin() const
				{
					//	TODO: Your code here
					Iterator iter;
					
					iter.head_ = this->head_;
					iter.tail_ = this->tail_;
					iter.cursor_ = this->head_;
					
					return iter;
				}
				
				/**
				 * Return an iterator that points to the last element (tail) of our list
				 */
				Iterator last() const
				{
					//	TODO: Your code here
					Iterator iter;
					
					iter.head_ = this->head_;
					iter.tail_ = this->tail_;
					iter.cursor_ = this->tail_;
					
					return iter;
				}
				
				/**
				 * Should return an iterator that represents being past the end of our nodes,
				 * or just that we are finished.
				 * You can make this a nullptr or use some other scheme of your choosing,
				 * 	as long as it works with the logic of the rest of your implementations.
				 */
				Iterator end() const
				{
					//	TODO: Your code here
					Iterator iter;
					
					iter.head_ = this->head_;
					iter.tail_ = this->tail_;
					iter.cursor_ = this->tail_->getNext();
					
					return iter;
				}
				
				/**
				 * Returns true if our list is empty
				 */
				bool empty() const
				{
					//	TODO: Your code here
					if(size==0)
					{
						return true;
					}
					else
					{
						return false;
					}	
				}
				
				/**
				 * Returns the current size of the list
				 * Should finish in constant time!
				 * (keep track of the size elsewhere)
				 */
				size_t size() const
				{
					//	TODO: Your code here
					
					return size_;
				}
				
				/**
				 * Clears our entire list, making it empty
				 * Remember: All removal operations should be memory-leak free.
				 */
				void clear()
				{
					//	TODO: Your code here
						while (size_ != 0)
					{
						Node* temp = head_;
						head_= head->getNext();
						delete temp;
						temp = nullptr;
						--size;
					}
				}
				
				/**
				 * Insert an element after the node pointed to by the pos Iterator
				 * 
				 * If the list is currently empty,
				 * 	ignore the iterator and just make the new node at the head/tail (list of length 1).
				 * 
				 * If the incoming iterator is this->end(), insert the element at the tail
				 * 
				 * Should return an iterator that points to the newly added node
				 * 
				 * To avoid repeated code, it might be a good idea to have other methods
				 * 	rely on this one.
				 */
				Iterator insert_after(Iterator pos, const T& value)
				{
					//	TODO: Your code here
					if(size_==0)
					{
						head_=new Node(value);
						tail_=head_;
						size = 1;
					}
					else
					{
						if(pos == this->end())
						{
							this->tail_->setNext(new Node(value));
							tail_ = tail_getNext();
							tail_->setNext(nullptr);
							++size;
						}
						else
						{
						Iterator cursor_2 = pos.cursor_->getNext();
						pos.cursor_->setNext(new Node(value));
						pos.cursor_->getNext()->setNext(cursor_2);
						}
					}
					//????
					return Iterator();
				}
				
				/**
				 * Insert a new element after the index pos.
				 * Should work with an empty list.
				 * 
				 * Should return an iterator pointing to the newly created node
				 * 
				 * To reduce repeated code, you may want to simply find
				 * 	an iterator to the node at the pos index, then
				 * 	send it to the other overload of this method.
				*/
				Iterator insert_after(size_t pos, const T& value)
				{
					//	TODO: Your code here
					Iterator iter;
					iter = iter + pos;
					
					insert_after(iter, value);
					
					return Iterator();
				}
				
				/**
				 * Erase the node pointed to by the Iterator's cursor.
				 * 
				 * If the 'pos' iterator does not point to a valid node,
				 * 	throw an std::range_error
				 * 
				 * Return an iterator to the node AFTER the one we erased,
				 * 	or this->end() if we just erased the tail
				 */
				Iterator erase(Iterator pos)
				{
					//	TODO: Your code here
					
					Iterator iter2 = pos.cursor_->getNext();
					iter->getPrev()->setNext(iter2);
					delete pos;
					pos = nullptr;
					return Iterator();
				}
				
				/**
				 * Add an element just after the one pointed to by the 'pos' iterator
				 * 
				 * Should return an iterator pointing to the newly created node
				 */
				Iterator push_after(Iterator pos, const T& value)
				{
					//	TODO: Your code here
						Iterator insert_after(size_t pos, const T& value)
					//
					return Iterator();
				}
				
				/**
				 * Add a new element to the front of our list.
				 */
				void push_front(const T& value)
				{
					//	TODO: Your code here
						Node* temp = new Node(value));
						head_->setPrev(temp);
						head_ = temp;
						++size;
					
				}
				
				/**
				 * Add an element to the end of this list.
				 * 
				 * Should return an iterator pointing to the newly created node.
				 */
				Iterator push_back(const T& value)
				{
					//	TODO: Your code here
						this->tail_->setNext(new Node(value));
						Node* temp = tail_;
						tail_ = tail_getNext();
						tail_->setNext(nullptr);
						tail_->setPrev(temp);
						++size;
					return Iterator();
				}
				
				/**
				 * Remove the node at the front of our list
				 * 
				 * Should throw an exception if our list is empty
				 */
				void pop_front()
				{
					//	TODO: Your code here
						this->head_->setPrev(new Node(value));
						Node* temp = head_;
						head_ = head_getPrev();
						head_->setPrev(nullptr);
						head_->setNext(temp);
						++size;
				}
				
				/**
				 * Remove the node at the end of our list
				 * 
				 * Should throw an exception if our list is empty
				 */
				void pop_back()
				{
					//	TODO: Your code here
						Node* temp = tail_;
						
						tail_ = tail_getPrev();
						tail_->setNext(nullptr);
						
						delete temp;
						temp = nullptr;
						
						--size;
				}
				
				/**
				 * Return a reference to the element at the front.
				 * 
				 * Throw an exception if the list is empty
				 */
				T& front()
				{
					//	TODO: Your code here
					return head_->getElement();
					//return *(new T());
				}
				
				/**
				 * Return a reference to the element at the back.
				 * 
				 * Throw an exception if the list is empty
				 */
				T& back()
				{
					//	TODO: Your code here
					return tail_->getElement();
					//return *(new T());
				}
				
				/**
				 * Return the element at an index
				 * 
				 * Should throw a range_error is out of bounds
				 */
				T& at(size_t index)
				{
					//	TODO: Your code here
					Iterator iter;
					iter = iter + index;
					
					return iter->getElement();
					
					//return *(new T());
				}
				
				/**
				 * Reverse the current list
				 * 
				 * It might be easy to consider the following:
				 * - Create a temp empty list
				 * - Iterate through the current list
				 * - For each item in the current list, push to the FRONT (not back)
				 * - Assign the current list to the temp list
				 * - Discard the temp list
				 */
				void reverse()
				{
					//	TODO: Your code here
					DoublyLinkedList<T> list2 (size_, T);
					Iterator iter;
					iter.cursor_ = head_;
					list2.size_ = size_;
					while (iter!= end())
					{
						list2.head_->setElement(iter.cursor_->getElement());
						list2.head_ = list2.head_->getNext();
						++iter;
					}
				}
				
				/**
				 * I bet you're happy I'm not making you do this.
				 * No tests will be run against this function,
				 * 	but feel free to try it out, as a challenge!
				 * 
				 * If I were doing this and didn't care too much for efficiency,
				 * 	I would probably create an extra helper function to swap two
				 * 	positions in the current list.
				 * Then I would simply sweep through the list and perform
				 *  the bubble-sort algorithm. Perhaps selection sort.
				 * 
				 * If you want a huge challenge, try implementing quicksort.
				 * 
				 * (but again, don't worry about this method; it will not be tested)
				 */
				void sort()
				{
					//	TODO: Your code here
				}
				
				/**
				 * Assignment operator
				 * 
				 * Clear this list and fill it with the others' values
				 * (by value, not by reference)
				 * 
				 * Return a reference to this list
				 */
				DoublyLinkedList<T>& operator =(DoublyLinkedList<T>& other)
				{
					//	TODO: Your code here
					clear();
					
					
					return *this;
				}
				
				/**
				 * Return true if the lists are "equal"
				 * 
				 * "Equal" here is defined as:
				 * - Same size
				 * - Elements at the same indexes would return true for their own comparison operators
				 * 
				 * In other words: "They contain all the same values"
				 * (no need to be references to each other)
				 */
				bool operator ==(DoublyLinkedList<T>& other)
				{
					//	TODO: Your code here
					while(iter ! = end())
					{
						if(iter->getElement() != other.head_->getElement())
						{
							return false;
						}
						else
						{
							++iter;
							other.head_ = other.head_->getNext();
						}
					}
					return true;
				}
				
				/**
				 * Return true if the lists are "not equal"
				 * 
				 * See the operator== stub for definition of "equal"
				 * 
				 * Probably want to avoid repeated code by relying on the other operator
				 */
				bool operator !=(DoublyLinkedList<T>& other)
				{
					//	TODO: Your code here
					if ( this == other)
					return false;
					else
					return true;
				}
				
			private:
				
				Node* head_ = nullptr;
				Node* tail_ = nullptr;
				size_t size_ = 0;
		};
	}
}

#endif
