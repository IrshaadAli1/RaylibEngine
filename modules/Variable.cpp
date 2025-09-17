//
// Created by Irshaad on 2025-09-08.
//
#pragma once
#include <functional>
#include <vector>

// Base class for common interface
class VariableBase {
public:
    virtual void resetChanged() = 0;
};

// Global array of VariableBase*
inline std::vector<VariableBase*> VarArray();

template <typename t>
class Variable : public VariableBase {
protected:
    using bind = std::function<void(t, Variable<t>)>;

    t var;
    t old;
    bool changed = false;

    static void defaultBind(t old, Variable self) {}

public:
    bind onChange = defaultBind;
    bind lateOnChange = defaultBind;

    // Constructors
    Variable(t value) {
        var = value;
        onChange = defaultBind;
        VarArray.push_back(this);
    }

    Variable(t value, bind binding) {
        var = value;
        onChange = binding;
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

    bool isChanged() const {
        return changed;
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

    // Reset changed flag
    void resetChanged() override {
        changed = false;
    }
};

inline void updateVars() {
    for (Variable v : VarArray) {
        if (v.isChanged()) {
            v.lateOnChange(v.getOld(), v);
        }
        v.resetChanged();
    }
}