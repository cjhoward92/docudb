# DocuDB

This is the start of a database project in C++.

Some design goals:
- Document storage like MongoDB
- Strong relationships between tables
- Stored procedures that can be executed via a DB client
- Timestamped changes that can be reverted with ease.

### Why not Rust?

Good question. Maybe I'll start over in Rust. Many database systems are written in C/C++ today,
so the mental mapping between languages is simpler if I stay consistent with the market. This doesn't
mean Rust doesn't make sense, or that Rust isn't a better choice. It's just the choice I made.

## Building

I am currently using CLion and using the built-in cmake support. I recommend you use that.

## Testing

Tests use [Catch2](https://github.com/catchorg/Catch2/tree/v2.x).