#ifndef _FUNCS_H_
#define _FUNCS_H_

void swapPtr(std::shared_ptr<Date>& a, std::shared_ptr<Date>& b);

std::shared_ptr<Date>& GreaterDateFirst(std::shared_ptr<Date>& a, std::shared_ptr<Date>& b);

std::shared_ptr<Date>& GreaterDateSecond(std::shared_ptr<Date>& a, std::shared_ptr<Date>& b);

std::shared_ptr<Date>& GreaterDateThird(std::shared_ptr<Date>& a, std::shared_ptr<Date>& b);

#endif //_FUNCS_H_
