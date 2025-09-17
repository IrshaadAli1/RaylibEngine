#pragma once
#include <functional>
#include <vector>

// Base class for common interface
class VariableBase {
public:
    virtual ~VariableBase() = default;  // Virtual destructor for proper cleanup

    // Pure virtual function to reset the changed state
    virtual void resetChanged() = 0;

    // Pure virtual function to check if the variable has changed
    virtual bool isChanged() const = 0;

    // Pure virtual function to update the variable
    virtual void update() = 0;
};

// Global array of VariableBase* (to store pointers to derived classes)
inline std::vector<VariableBase*> VarArray;

template <typename t>
class Variable : public VariableBase {
protected:
    using bind = std::function<void(t, Variable<t>&)>;

    t var;
    t old;
    bool changed = false;

    static void defaultBind(t old, Variable<t>& self) {}

public:
    bind onChange = defaultBind;
    bind lateOnChange = defaultBind;

    // Constructor
    Variable(t value) {
        var = value;
        onChange = defaultBind;

        // Add the current object as a raw pointer to the global array
        VarArray.push_back(this);
    }

    Variable(t value, bind binding) {
        var = value;
        onChange = binding;

        // Add the current object as a raw pointer to the global array
        VarArray.push_back(this);
    }

    // Set & Get
    void set(t value) {
        old = var;
        var = value;
        changed = true;
        onChange(old, *this);
    }

    t get() const { return var; }
    t getOld() const { return old; }

    // Binding
    void bindChange(bind newBind) {
        onChange = newBind;
    }

    void bindChange() {
        onChange = defaultBind;
    }

    void bindLateChange(bind newBind) {
        lateOnChange = newBind;
    }

    void bindLateChange() {
        lateOnChange = defaultBind;
    }

    bool isChanged() const override {
        return changed;
    }

    void resetChanged() override {
        changed = false;
    }

    void update() override {
        if (isChanged()) {
            lateOnChange(old, *this);
        }
        resetChanged();
    }

    // Operator overloads

    // Prefix increment/decrement
    void operator++() { set(var + 1); }
    void operator--() { set(var - 1); }

    // Compound assignment with Variable
    void operator+=(const Variable& other) { set(var + other.var); }
    void operator-=(const Variable& other) { set(var - other.var); }
    void operator*=(const Variable& other) { set(var * other.var); }
    void operator/=(const Variable& other) { set(var / other.var); }
    void operator%=(const Variable& other) { set(var % other.var); }

    // Compound assignment with raw t
    void operator+=(const t& value) { set(var + value); }
    void operator-=(const t& value) { set(var - value); }
    void operator*=(const t& value) { set(var * value); }
    void operator/=(const t& value) { set(var / value); }
    void operator%=(const t& value) { set(var % value); }

    // Arithmetic operators
    Variable operator+(const Variable& other) const { return Variable(var + other.var); }
    Variable operator-(const Variable& other) const { return Variable(var - other.var); }
    Variable operator*(const Variable& other) const { return Variable(var * other.var); }
    Variable operator/(const Variable& other) const { return Variable(var / other.var); }
    Variable operator%(const Variable& other) const { return Variable(var % other.var); }

    // Arithmetic with raw t
    Variable operator+(const t& value) const { return Variable(var + value); }
    Variable operator-(const t& value) const { return Variable(var - value); }
    Variable operator*(const t& value) const { return Variable(var * value); }
    Variable operator/(const t& value) const { return Variable(var / value); }
    Variable operator%(const t& value) const { return Variable(var % value); }

    // Comparison operators
    bool operator==(const Variable& other) const { return var == other.var; }
    bool operator!=(const Variable& other) const { return var != other.var; }
    bool operator<(const Variable& other) const { return var < other.var; }
    bool operator<=(const Variable& other) const { return var <= other.var; }
    bool operator>(const Variable& other) const { return var > other.var; }
    bool operator>=(const Variable& other) const { return var >= other.var; }

    // Assignment
    Variable& operator=(const t& value) {
        set(value);
        return *this;
    }

    Variable& operator=(const Variable& other) {
        if (this != &other) set(other.var);
        return *this;
    }

    // Implicit conversion to t
    operator t() const { return var; }
};

// Function to update all variables
inline void updateVars() {
    for (auto* v : VarArray) {  // Use pointer dereferencing here
        v->update();  // Call update on each variable object
    }
}
