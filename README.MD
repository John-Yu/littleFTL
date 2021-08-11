**littleFTL**

​    ----FTL based on littleFS core technologis



  This is an experimental project to quickly realize the feasibility of an FTL based on the core technology of  [littleFS](https://github.com/John-Yu/littleFS) .

  It took about 10 minutes from conception to implementation. So the code looks rough, but the experimental results are satisfactory.

  Thanks to the compact design of the metadata pair, the entire index area occupies very small FLASH space, which brings two benefits.

1. High space utilization rate

2. File retrieval is very fast

  In addition, based on the design idea of the CTZ skip table, a complete physical block stores the contents of the entire logical sector, and there is a one-to-one correspondence, so the lftl_map_find() API can be conveniently implemented.

Because of the core technology based on littleFS, littleFTL is born with the advantages of littleFS.

1. low memory footprint
2. power loss protection
3. wear levelling

**Test**

 Use VS2017 , open test.sln .
