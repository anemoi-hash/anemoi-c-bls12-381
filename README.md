# C implementation of Anemoi over the scalar field of BLS12-381

**Warning: this is not a C implementation that can be used for bindings.**
The library has been written first to be used as a backend for the [OCaml
implementation](https://gitlab.com/tezos/tezos/-/tree/master/src/lib_bls12_381_hash) and some changes are work in progress to be suitable for C usage and bindings. **Please do not use this version at the moment**
The interface might not be suitable enough for C users.

## Compile

Get [blst](https://github.com/supranational/blst):
```
git submodule init
git submodule update
```

And run `make`
