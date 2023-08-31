//compiler_log.h
class CompilerLog{
public:
    void PrintMethodTime() const;
private:
    std::map<std::string, double> timePassMap_ {};
}

class TimeScope : public ClockScope {
public:
    TimeScope(std::string name, std::string methodName, const CompilerLog* log){}
    ~TimeScope(){
        打印单个method数据;
        log_->GetPassTimeMap();
        //填充数据进入timePassMap_;
    }
private:
    const CompilerLog *log_ {nullptr};
}                                                      //pass.h
                                                       TimeScope("pass", methodName, data->GetLog());

//compiler_log.cpp
void CompilerLog::PrintPassTime() const
{
    //加减数据并打印
}

//pass_manager.cpp
bool PassManager::Compile(xxx)
{
    ...
    log->PrintPassTime();
}