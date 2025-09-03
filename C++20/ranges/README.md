# Ranges and Views

std::range - A range is a sequence of elements that can be iterated over. The STL containers are ranges.

std::views - A view is a lightweight, non-owning reference to a range. Views do not store elements, but provide a way to access and transform them.

pipe - A pipe is a way to compose multiple views together. It allows you to create a pipeline of transformations that can be applied to a range.
