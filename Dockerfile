RUN cmake .. && cmake --build .

FROM debian:11-slim
COPY --from=build /csv2xlsx/linux-build/csv2xlsx /usr/local/bin
