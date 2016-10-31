#include "../redismodule.h"
#include "../rmutil/util.h"
#include "../rmutil/strings.h"
#include "../rmutil/test_util.h"
#include <math.h>

// Method to convert RedisModuleReply object to long long int

long long int GetArgVal(RedisModuleCtx *ctx, RedisModuleCallReply *rep) {
	if (RedisModule_CallReplyType(rep) == REDISMODULE_REPLY_STRING) {
    	RedisModuleString *mystr = RedisModule_CreateStringFromCallReply(rep);
    	long long arg;
    	if (RedisModule_StringToLongLong(mystr,&arg) == REDISMODULE_OK) {
    		return arg;
		}
		else {
			RedisModule_ReplyWithError(ctx,"INVALID VALUE");
		}
   	}    
	else {
  		RedisModule_ReplyWithError(ctx,"INVALIDs VALUE");
  	}
  	return -1;
  
}

// Method to calculte the sum of two keys' values and store the sum in a new key

int Sum(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

 // we must have at least 4 args
  if (argc < 4) {
    return RedisModule_WrongArity(ctx);
  }

  // init auto memory for created strings
  RedisModule_AutoMemory(ctx);
  long long arg1 ,arg2, result;
  RedisModuleCallReply *rep =
      RedisModule_Call(ctx, "GET", "s", argv[1]);
  RMUTIL_ASSERT_NOERROR(rep);
  arg1 = GetArgVal(ctx, rep);
  rep =
      RedisModule_Call(ctx, "GET", "s", argv[2]);
  RMUTIL_ASSERT_NOERROR(rep);
  arg2 = GetArgVal(ctx, rep);
  result = arg1 + arg2;
  rep =
      RedisModule_Call(ctx, "SET", "sl", argv[3],result);
  RMUTIL_ASSERT_NOERROR(rep);
  RedisModule_ReplyWithLongLong(ctx, result);

  return REDISMODULE_OK;
}

// Method to calculte the difference of two keys' values and store the difference in a new key

int Sub(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

 // we must have at least 4 args
  if (argc < 4) {
    return RedisModule_WrongArity(ctx);
  }

  // init auto memory for created strings
  RedisModule_AutoMemory(ctx);
  long long arg1 ,arg2, result;
  RedisModuleCallReply *rep =
      RedisModule_Call(ctx, "GET", "s", argv[1]);
  RMUTIL_ASSERT_NOERROR(rep);
  arg1 = GetArgVal(ctx, rep);
  rep =
      RedisModule_Call(ctx, "GET", "s", argv[2]);
  RMUTIL_ASSERT_NOERROR(rep);
  arg2 = GetArgVal(ctx, rep);
  result = arg1 - arg2;
  rep =
      RedisModule_Call(ctx, "SET", "sl", argv[3],result);
  RMUTIL_ASSERT_NOERROR(rep);
  RedisModule_ReplyWithLongLong(ctx, result);

  return REDISMODULE_OK;
}

// Method to calculte the product of two keys' values and store the product in a new key

int Prod(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

 // we must have at least 4 args
  if (argc < 4) {
    return RedisModule_WrongArity(ctx);
  }

  // init auto memory for created strings
  RedisModule_AutoMemory(ctx);
  long long arg1 ,arg2, result;
  RedisModuleCallReply *rep =
      RedisModule_Call(ctx, "GET", "s", argv[1]);
  RMUTIL_ASSERT_NOERROR(rep);
  arg1 = GetArgVal(ctx, rep);
  rep =
      RedisModule_Call(ctx, "GET", "s", argv[2]);
  RMUTIL_ASSERT_NOERROR(rep);
  arg2 = GetArgVal(ctx, rep);
  result = arg1 * arg2;
  rep =
      RedisModule_Call(ctx, "SET", "sl", argv[3],result);
  RMUTIL_ASSERT_NOERROR(rep);
  RedisModule_ReplyWithLongLong(ctx, result);

  return REDISMODULE_OK;
}

// Method to calculte the result of dividing two keys' values (first divided by second) 
// and store the quotient in a new key

int Div(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

 // we must have at least 4 args
  if (argc < 4) {
    return RedisModule_WrongArity(ctx);
  }

  // init auto memory for created strings
  RedisModule_AutoMemory(ctx);
  long long arg1 ,arg2, result;
  RedisModuleCallReply *rep =
      RedisModule_Call(ctx, "GET", "s", argv[1]);
  RMUTIL_ASSERT_NOERROR(rep);
  arg1 = GetArgVal(ctx, rep);
  rep =
      RedisModule_Call(ctx, "GET", "s", argv[2]);
  RMUTIL_ASSERT_NOERROR(rep);
  arg2 = GetArgVal(ctx, rep);
  if(arg2 == 0) {
  	RedisModule_ReplyWithError(ctx, "CANNOT DIVIDE BY ZERO!!");
  }
  else {
    result = arg1 / arg2;
    rep =
        RedisModule_Call(ctx, "SET", "sl", argv[3],result);
    RMUTIL_ASSERT_NOERROR(rep);
    RedisModule_ReplyWithLongLong(ctx, result);
  }

  return REDISMODULE_OK;
}

// Method to calculte the remainder after dividing two keys' values (first divided by second) 
// and store the remainder in a new key

int Mod(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

 // we must have at least 4 args
  if (argc < 4) {
    return RedisModule_WrongArity(ctx);
  }

  // init auto memory for created strings
  RedisModule_AutoMemory(ctx);
  long long arg1 ,arg2, result;
  RedisModuleCallReply *rep =
      RedisModule_Call(ctx, "GET", "s", argv[1]);
  RMUTIL_ASSERT_NOERROR(rep);
  arg1 = GetArgVal(ctx, rep);
  rep =
      RedisModule_Call(ctx, "GET", "s", argv[2]);
  RMUTIL_ASSERT_NOERROR(rep);
  arg2 = GetArgVal(ctx, rep);
  if(arg2 == 0) {
  	RedisModule_ReplyWithError(ctx, "CANNOT DIVIDE BY ZERO!!");
  }
  else {
    result = arg1 % arg2;
    rep =
        RedisModule_Call(ctx, "SET", "sl", argv[3],result);
    RMUTIL_ASSERT_NOERROR(rep);
    RedisModule_ReplyWithLongLong(ctx, result);
  }

  return REDISMODULE_OK;
}

// Method to calculte the result of raising the first key's value to the
// power of second key's value

int Pow(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

 // we must have at least 4 args
  if (argc < 4) {
    return RedisModule_WrongArity(ctx);
  }

  // init auto memory for created strings
  RedisModule_AutoMemory(ctx);
  long long arg1 ,arg2, result;
  RedisModuleCallReply *rep =
      RedisModule_Call(ctx, "GET", "s", argv[1]);
  RMUTIL_ASSERT_NOERROR(rep);
  arg1 = GetArgVal(ctx, rep);
  rep =
      RedisModule_Call(ctx, "GET", "s", argv[2]);
  RMUTIL_ASSERT_NOERROR(rep);
  arg2 = GetArgVal(ctx, rep);
  result = (long long)pow(arg1, arg2);
  rep =
      RedisModule_Call(ctx, "SET", "sl", argv[3],result);
  RMUTIL_ASSERT_NOERROR(rep);
  RedisModule_ReplyWithLongLong(ctx, result);
 

  return REDISMODULE_OK;
}

// Method to increment all the values in a list in a given range by a given value 

int LincrBy(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

 // we must have at least 5 args
  if (argc != 5) {
    return RedisModule_WrongArity(ctx);
  }

  // init auto memory for created strings
  RedisModule_AutoMemory(ctx);
  long long val, startIndex, endIndex;
  RedisModuleCallReply *rep =
      RedisModule_Call(ctx, "LLEN", "s", argv[1]);
  RMUTIL_ASSERT_NOERROR(rep);
  long long listLength;
  listLength = RedisModule_CallReplyInteger(rep);
  long long listEnd = listLength - 1;
  if(RedisModule_StringToLongLong(argv[2], &val) != REDISMODULE_OK) {
  	RedisModule_ReplyWithError(ctx, "INVALID INCREMENT VALUE");
  }
  if(RedisModule_StringToLongLong(argv[3], &startIndex) != REDISMODULE_OK) {
  	RedisModule_ReplyWithError(ctx, "INVALID START INDEX");
  }
  if(RedisModule_StringToLongLong(argv[4], &endIndex) != REDISMODULE_OK) {
  	RedisModule_ReplyWithError(ctx, "INVALID END INDEX");
  }
  if(startIndex < 0 || endIndex < -1) {
  	RedisModule_ReplyWithError(ctx,"STARTINDEX CANNOT BE NEGATIVE AND ENDINDEX CANNOT BE LESS THAN -1");
  }

  if(startIndex > listEnd || endIndex > listEnd) {
  	RedisModule_ReplyWithError(ctx,"INDEX POSITION OUT OF LIMIT");
  }

  if(startIndex > endIndex && endIndex != -1) {
  	RedisModule_ReplyWithError(ctx,"STARTINDEX SHOULD BE LESS THAN OR EQUAL TO ENDINDEX (EXCEPT WHEN ENDINDEX != -1");
  }

  if(endIndex == -1) {
  	endIndex = listEnd;
  }

  for(long long i = startIndex;i <= endIndex;i++) {

  	RedisModuleString *index = RedisModule_CreateStringFromLongLong(ctx, i);
  	rep =
      RedisModule_Call(ctx, "LINDEX", "ss", argv[1], index);
    RMUTIL_ASSERT_NOERROR(rep);
    long long element = GetArgVal(ctx, rep);  
    element = element + val;  
    RedisModuleString *finalValue = RedisModule_CreateStringFromLongLong(ctx, element);
    rep =
      RedisModule_Call(ctx, "LSET", "sss", argv[1], index, finalValue);
    RMUTIL_ASSERT_NOERROR(rep);
  }

  RedisModule_ReplyWithLongLong(ctx, endIndex - startIndex + 1);
  return REDISMODULE_OK;
}

// Method to calculate sum of a range of elements of a list

int Lrsum(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

 // we must have at least 4 args
  if (argc < 4) {
    return RedisModule_WrongArity(ctx);
  }

  // init auto memory for created strings
  RedisModule_AutoMemory(ctx);
  long long startIndex, endIndex, rsum = 0;
  RedisModuleCallReply *rep =
      RedisModule_Call(ctx, "LLEN", "s", argv[1]);
  RMUTIL_ASSERT_NOERROR(rep);
  long long listLength;
  listLength = RedisModule_CallReplyInteger(rep);
  long long listEnd = listLength - 1;
  if(RedisModule_StringToLongLong(argv[2], &startIndex) != REDISMODULE_OK) {
  	RedisModule_ReplyWithError(ctx, "INVALID START INDEX");
  }
  if(RedisModule_StringToLongLong(argv[3], &endIndex) != REDISMODULE_OK) {
  	RedisModule_ReplyWithError(ctx, "INVALID END INDEX");
  }
  if(startIndex < 0 || endIndex < -1) {
  	RedisModule_ReplyWithError(ctx,"STARTINDEX CANNOT BE NEGATIVE AND ENDINDEX CANNOT BE LESS THAN -1");
  }

  if(startIndex > listEnd || endIndex > listEnd) {
  	RedisModule_ReplyWithError(ctx,"INDEX POSITION OUT OF LIMIT");
  }

  if(startIndex > endIndex && endIndex != -1) {
  	RedisModule_ReplyWithError(ctx,"STARTINDEX SHOULD BE LESS THAN OR EQUAL TO ENDINDEX (EXCEPT WHEN ENDINDEX != -1");
  }

  if(endIndex == -1) {
  	endIndex = listEnd;
  }

  for(long long i = startIndex;i <= endIndex;i++) {

    RedisModuleString *index = RedisModule_CreateStringFromLongLong(ctx, i);
  	rep =
      RedisModule_Call(ctx, "LINDEX", "ss", argv[1], index);
    RMUTIL_ASSERT_NOERROR(rep);
    long long element = GetArgVal(ctx, rep);  
    rsum = rsum + element;
  }

  if(argc == 5) {
  	rep =
      RedisModule_Call(ctx, "SET", "sl", argv[4],rsum);
    RMUTIL_ASSERT_NOERROR(rep);  
  }
  RedisModule_ReplyWithLongLong(ctx, rsum);
  return REDISMODULE_OK;
}

// Method to find the largest element in a specified range in a list

int Lrmax(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

 // we must have at least 4 args
  if (argc < 4) {
    return RedisModule_WrongArity(ctx);
  }

  // init auto memory for created strings
  RedisModule_AutoMemory(ctx);
  long long startIndex, endIndex, max = 0;
  RedisModuleCallReply *rep =
      RedisModule_Call(ctx, "LLEN", "s", argv[1]);
  RMUTIL_ASSERT_NOERROR(rep);
  long long listLength;
  listLength = RedisModule_CallReplyInteger(rep);
  long long listEnd = listLength - 1;
  if(RedisModule_StringToLongLong(argv[2], &startIndex) != REDISMODULE_OK) {
  	RedisModule_ReplyWithError(ctx, "INVALID START INDEX");
  }
  if(RedisModule_StringToLongLong(argv[3], &endIndex) != REDISMODULE_OK) {
  	RedisModule_ReplyWithError(ctx, "INVALID END INDEX");
  }
  if(startIndex < 0 || endIndex < -1) {
  	RedisModule_ReplyWithError(ctx,"STARTINDEX CANNOT BE NEGATIVE AND ENDINDEX CANNOT BE LESS THAN -1");
  }

  if(startIndex > listEnd || endIndex > listEnd) {
  	RedisModule_ReplyWithError(ctx,"INDEX POSITION OUT OF LIMIT");
  }

  if(startIndex > endIndex && endIndex != -1) {
  	RedisModule_ReplyWithError(ctx,"STARTINDEX SHOULD BE LESS THAN OR EQUAL TO ENDINDEX (EXCEPT WHEN ENDINDEX != -1");
  }

  if(endIndex == -1) {
  	endIndex = listEnd;
  }

  for(long long i = startIndex;i <= endIndex;i++) {

    RedisModuleString *index = RedisModule_CreateStringFromLongLong(ctx, i);
  	rep =
      RedisModule_Call(ctx, "LINDEX", "ss", argv[1], index);
    RMUTIL_ASSERT_NOERROR(rep);
    long long element = GetArgVal(ctx, rep);  
    if(i == startIndex) {
    	max = element;
    }
    else {
    	max = element > max ? element : max;
    }
  }

  if(argc == 5) {
  	rep =
      RedisModule_Call(ctx, "SET", "sl", argv[4],max);
    RMUTIL_ASSERT_NOERROR(rep);  
  }
  RedisModule_ReplyWithLongLong(ctx, max);
  return REDISMODULE_OK;
}

// Method to find the smallest element in a specified range in a list.

int Lrmin(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

 // we must have at least 4 args
  if (argc < 4) {
    return RedisModule_WrongArity(ctx);
  }

  // init auto memory for created strings
  RedisModule_AutoMemory(ctx);
  long long startIndex, endIndex, min = 0;
  RedisModuleCallReply *rep =
      RedisModule_Call(ctx, "LLEN", "s", argv[1]);
  RMUTIL_ASSERT_NOERROR(rep);
  long long listLength;
  listLength = RedisModule_CallReplyInteger(rep);
  long long listEnd = listLength - 1;
  if(RedisModule_StringToLongLong(argv[2], &startIndex) != REDISMODULE_OK) {
  	RedisModule_ReplyWithError(ctx, "INVALID START INDEX");
  }
  if(RedisModule_StringToLongLong(argv[3], &endIndex) != REDISMODULE_OK) {
  	RedisModule_ReplyWithError(ctx, "INVALID END INDEX");
  }
  if(startIndex < 0 || endIndex < -1) {
  	RedisModule_ReplyWithError(ctx,"STARTINDEX CANNOT BE NEGATIVE AND ENDINDEX CANNOT BE LESS THAN -1");
  }

  if(startIndex > listEnd || endIndex > listEnd) {
  	RedisModule_ReplyWithError(ctx,"INDEX POSITION OUT OF LIMIT");
  }

  if(startIndex > endIndex && endIndex != -1) {
  	RedisModule_ReplyWithError(ctx,"STARTINDEX SHOULD BE LESS THAN OR EQUAL TO ENDINDEX (EXCEPT WHEN ENDINDEX != -1)");
  }

  if(endIndex == -1) {
  	endIndex = listEnd;
  }

  for(long long i = startIndex;i <= endIndex;i++) {

    RedisModuleString *index = RedisModule_CreateStringFromLongLong(ctx, i);
  	rep =
      RedisModule_Call(ctx, "LINDEX", "ss", argv[1], index);
    RMUTIL_ASSERT_NOERROR(rep);
    long long element = GetArgVal(ctx, rep);  
    if(i == startIndex) {
    	min = element;
    }
    else {
    	min = element < min ? element : min;
    }
  }

  if(argc == 5) {
  	rep =
      RedisModule_Call(ctx, "SET", "sl", argv[4],min);
    RMUTIL_ASSERT_NOERROR(rep);  
  }
  RedisModule_ReplyWithLongLong(ctx, min);
  return REDISMODULE_OK;
}

// Method to find the sum of the corresponding elements of two lists and store the result in a new list.

int Llsum(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

 // we must have at least 4 args
  if (argc < 4) {
    return RedisModule_WrongArity(ctx);
  }

  // init auto memory for created strings
  long long listLength1, listLength2;
  RedisModule_AutoMemory(ctx);
  RedisModuleCallReply *rep =
      RedisModule_Call(ctx, "LLEN", "s", argv[1]);
  RMUTIL_ASSERT_NOERROR(rep);
  listLength1 = RedisModule_CallReplyInteger(rep);
  rep =
      RedisModule_Call(ctx, "LLEN", "s", argv[2]);
  RMUTIL_ASSERT_NOERROR(rep);
  listLength2 = RedisModule_CallReplyInteger(rep);

  if(listLength1 != listLength2) {
  	RedisModule_ReplyWithError(ctx,"LENGTH OF BOTH THE LISTS SHOULD BE EQUAL");
  }
  
  for(long long i = 0;i < listLength1;i++) {

    RedisModuleString *index = RedisModule_CreateStringFromLongLong(ctx, i);
  	rep =
      RedisModule_Call(ctx, "LINDEX", "ss", argv[1], index);
    RMUTIL_ASSERT_NOERROR(rep);
    long long element1 = GetArgVal(ctx, rep);
	rep =
      RedisModule_Call(ctx, "LINDEX", "ss", argv[2], index);
    RMUTIL_ASSERT_NOERROR(rep);
    long long element2 = GetArgVal(ctx, rep);
	long long elementsum = element1 + element2;
    rep =
      RedisModule_Call(ctx, "RPUSH", "sl", argv[3], elementsum);
    RMUTIL_ASSERT_NOERROR(rep);
  }

  RedisModule_ReplyWithLongLong(ctx, listLength1);
  return REDISMODULE_OK;
}

// Method to insert the value of a key into a list from left using the key name.

int Llkpush(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

 // we must have at least 4 args
  if (argc < 3) {
    return RedisModule_WrongArity(ctx);
  }

  // init auto memory for created strings
  RedisModule_AutoMemory(ctx);
  
  for(long long i = 2;i < argc;i++) {
  	RedisModuleCallReply *rep =
      RedisModule_Call(ctx, "GET", "s", argv[i]);
    RMUTIL_ASSERT_NOERROR(rep);
    RedisModuleString *value = RedisModule_CreateStringFromCallReply(rep);
	rep =
      RedisModule_Call(ctx, "LPUSH", "ss", argv[1], value);
    RMUTIL_ASSERT_NOERROR(rep);
  }

  RedisModule_ReplyWithLongLong(ctx, argc-2);
  return REDISMODULE_OK;
}

// Method to insert the value of a key into a list from right using the key name.

int Lrkpush(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

 // we must have at least 4 args
  if (argc < 3) {
    return RedisModule_WrongArity(ctx);
  }

  // init auto memory for created strings
  RedisModule_AutoMemory(ctx);
  
  for(long long i = 2;i < argc;i++) {
  	RedisModuleCallReply *rep =
      RedisModule_Call(ctx, "GET", "s", argv[i]);
    RMUTIL_ASSERT_NOERROR(rep);
    RedisModuleString *value = RedisModule_CreateStringFromCallReply(rep);
	rep =
      RedisModule_Call(ctx, "RPUSH", "ss", argv[1], value);
    RMUTIL_ASSERT_NOERROR(rep);
  }

  RedisModule_ReplyWithLongLong(ctx, argc-2);
  return REDISMODULE_OK;
}

int RedisModule_OnLoad(RedisModuleCtx *ctx) {

  // Register the module itself
  if (RedisModule_Init(ctx, "arith", 1, REDISMODULE_APIVER_1) ==
      REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }

  if (RedisModule_CreateCommand(ctx, "arith.sum", Sum, "readonly",
                                1, 1, 1) == REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }

  if (RedisModule_CreateCommand(ctx, "arith.sub", Sub, "readonly",
                                1, 1, 1) == REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }

  if (RedisModule_CreateCommand(ctx, "arith.prod", Prod, "readonly",
                                1, 1, 1) == REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }

  if (RedisModule_CreateCommand(ctx, "arith.div", Div, "readonly",
                                1, 1, 1) == REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }

  if (RedisModule_CreateCommand(ctx, "arith.mod", Mod, "readonly",
                                1, 1, 1) == REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }

  if (RedisModule_CreateCommand(ctx, "arith.pow", Pow, "readonly",
                                1, 1, 1) == REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }

  if (RedisModule_CreateCommand(ctx, "arith.lincrby", LincrBy, "readonly",
                                1, 1, 1) == REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }

  if (RedisModule_CreateCommand(ctx, "arith.lrsum", Lrsum, "readonly",
                                1, 1, 1) == REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }

  if (RedisModule_CreateCommand(ctx, "arith.lrmax", Lrmax, "readonly",
                                1, 1, 1) == REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }

  if (RedisModule_CreateCommand(ctx, "arith.lrmin", Lrmin, "readonly",
                                1, 1, 1) == REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }

  if (RedisModule_CreateCommand(ctx, "arith.llsum", Llsum, "readonly",
                                1, 1, 1) == REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }

  if (RedisModule_CreateCommand(ctx, "arith.llkpush", Llkpush, "readonly",
                                1, 1, 1) == REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }

  if (RedisModule_CreateCommand(ctx, "arith.lrkpush", Lrkpush, "readonly",
                                1, 1, 1) == REDISMODULE_ERR) {
    return REDISMODULE_ERR;
  }


  return REDISMODULE_OK;
}
