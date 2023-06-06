#include "MagicalContainer.hpp"

namespace ariel
{
    // ----------------MagicalContainer-----------------

    int MagicalContainer::size()
    {
        return original.size();
    }

    void MagicalContainer::addElement(int Elem)
    {
        original.push_back(Elem);
        sort(original.begin(), original.end());
        primed.clear();
        crossing.clear();
        ascending.clear();
        originalPrime();
        originalCross();
        originalAscend();
    }

    void MagicalContainer::removeElement(int Elem)
    {
        bool flag = false;
        for (int j : original)
            if (j == Elem)
                flag = true;
        if (!flag)
            throw std::runtime_error("Invalid argument");

        auto i = lower_bound(original.begin(), original.end(), Elem);
        if (i != original.end() && *i == Elem)
            original.erase(i);
        primed.clear();
        crossing.clear();
        ascending.clear();
        originalPrime();
        originalCross();
        originalAscend();
    }

    void MagicalContainer::originalAscend()
    {
        for (auto i = original.begin(); i != original.end(); i++)
            ascending.push_back(&(*i));
    }

    void MagicalContainer::originalPrime()
    {
        for (auto i = original.begin(); i != original.end(); i++)
            if (isPrime(*i))
                primed.push_back(&(*i));
    }

    void MagicalContainer::originalCross()
    {
        size_t left = 0;
        size_t right = original.size() - 1;
        while (left <= right)
        {
            crossing.push_back(&original[left++]);

            if (left <= right)
                crossing.push_back(&original[right--]);
        }
    }

    bool MagicalContainer::isPrime(int number)
    {
        if (number < 2)
            return false;
        int sqrtNumber = sqrt(number);
        for (int i = 2; i <= sqrtNumber; ++i)
            if (number % i == 0)
                return false;
        return true;
    }

    // --------------------------------------------------
    // ----------------AscendingIterator-----------------
    // --------------------------------------------------

    // Destructors N' Constructors
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container), asc(container.ascending.begin()), size(0) {}
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), asc(other.asc), size(other.size) {}
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept { return *this; }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (&other.container != &container)
            throw std::runtime_error("Invaild argument");
        asc = other.asc;
        size = other.size;
        return *this;
    }

    // Operators
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        if (&other.container != &container)
            throw std::runtime_error("invaild argument");
        return asc == other.asc;
    }
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return !(other == *this);
    }
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return (size > other.size);
    }
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return (size < other.size);
    }
    int MagicalContainer::AscendingIterator::operator*()
    {
        if (asc == container.ascending.end())
            throw std::runtime_error("Out of range");
        return **asc;
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (asc == container.ascending.end())
            throw std::runtime_error("Out of range");
        ++size;
        ++asc;
        return *this;
    }

    // Begin N' End
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin()
    {
        asc = container.ascending.begin();
        size = 0;
        return *this;
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end()
    {
        asc = container.ascending.end();
        size = container.ascending.size();
        return *this;
    }

    // --------------------------------------------------
    // ----------------SideCrossIterator-----------------
    // --------------------------------------------------

    // Destructors N' Constructors
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(container), cross(container.crossing.begin()), size(0) {}
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container), cross(other.cross), size(other.size) {}
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept { return *this; }
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (&other.container != &container)
            throw std::runtime_error("Invaild argument");
        cross = other.cross;
        size = other.size;
        return *this;
    }

    // Operators
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        if (&other.container != &container)
            throw std::runtime_error("invaild argument");
        return cross == other.cross;
    }
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(other == *this);
    }
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return (size > other.size);
    }
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return (size < other.size);
    }
    int MagicalContainer::SideCrossIterator::operator*()
    {
        if (cross == container.crossing.end())
            throw std::runtime_error("Out of range");
        return **cross;
    }
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (cross == container.crossing.end())
            throw std::runtime_error("Out of range");
        ++size;
        ++cross;
        return *this;
    }

    // Begin N' End
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::begin()
    {
        cross = container.crossing.begin();
        size = 0;
        return *this;
    }
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::end()
    {
        cross = container.crossing.end();
        size = container.crossing.size();
        return *this;
    }

    // --------------------------------------------------
    // -------------------PrimeIterator------------------
    // --------------------------------------------------

    // Destructors N' Constructors
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container), prime(container.primed.begin()), size(0) {}
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), prime(other.prime), size(other.size) {}
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept { return *this; }
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (&other.container != &container)
            throw std::runtime_error("Invaild argument");
        prime = other.prime;
        size = other.size;
        return *this;
    }

    // Operators
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        if (&other.container != &container)
            throw std::runtime_error("invaild argument");
        return prime == other.prime;
    }
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(other == *this);
    }
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return (size > other.size);
    }
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return (size < other.size);
    }
    int MagicalContainer::PrimeIterator::operator*()
    {
        if (prime == container.primed.end())
            throw std::runtime_error("Out of range");
        return **prime;
    }
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (prime == container.primed.end())
            throw std::runtime_error("Out of range");
        ++size;
        ++prime;
        return *this;
    }

    // Begin N' End
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::begin()
    {
        prime = container.primed.begin();
        size = 0;
        return *this;
    }
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::end()
    {
        prime = container.primed.end();
        size = container.primed.size();
        return *this;
    }
};