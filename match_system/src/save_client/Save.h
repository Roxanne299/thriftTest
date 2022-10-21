/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Save_H
#define Save_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "save_types.h"

namespace save_service {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class SaveIf {
 public:
  virtual ~SaveIf() {}

  /**
   * username: myserver的名称
   * password: myserver的密码的md5sum的前8位
   * 用户名密码验证成功会返回0，验证失败会返回1
   * 验证成功后，结果会被保存到myserver:homework/lesson_6/result.txt中
   * 
   * @param username
   * @param password
   * @param player1_id
   * @param player2_id
   */
  virtual int32_t save_data(const std::string& username, const std::string& password, const int32_t player1_id, const int32_t player2_id) = 0;
};

class SaveIfFactory {
 public:
  typedef SaveIf Handler;

  virtual ~SaveIfFactory() {}

  virtual SaveIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(SaveIf* /* handler */) = 0;
};

class SaveIfSingletonFactory : virtual public SaveIfFactory {
 public:
  SaveIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<SaveIf>& iface) : iface_(iface) {}
  virtual ~SaveIfSingletonFactory() {}

  virtual SaveIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(SaveIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<SaveIf> iface_;
};

class SaveNull : virtual public SaveIf {
 public:
  virtual ~SaveNull() {}
  int32_t save_data(const std::string& /* username */, const std::string& /* password */, const int32_t /* player1_id */, const int32_t /* player2_id */) {
    int32_t _return = 0;
    return _return;
  }
};

typedef struct _Save_save_data_args__isset {
  _Save_save_data_args__isset() : username(false), password(false), player1_id(false), player2_id(false) {}
  bool username :1;
  bool password :1;
  bool player1_id :1;
  bool player2_id :1;
} _Save_save_data_args__isset;

class Save_save_data_args {
 public:

  Save_save_data_args(const Save_save_data_args&);
  Save_save_data_args& operator=(const Save_save_data_args&);
  Save_save_data_args() : username(), password(), player1_id(0), player2_id(0) {
  }

  virtual ~Save_save_data_args() throw();
  std::string username;
  std::string password;
  int32_t player1_id;
  int32_t player2_id;

  _Save_save_data_args__isset __isset;

  void __set_username(const std::string& val);

  void __set_password(const std::string& val);

  void __set_player1_id(const int32_t val);

  void __set_player2_id(const int32_t val);

  bool operator == (const Save_save_data_args & rhs) const
  {
    if (!(username == rhs.username))
      return false;
    if (!(password == rhs.password))
      return false;
    if (!(player1_id == rhs.player1_id))
      return false;
    if (!(player2_id == rhs.player2_id))
      return false;
    return true;
  }
  bool operator != (const Save_save_data_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Save_save_data_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Save_save_data_pargs {
 public:


  virtual ~Save_save_data_pargs() throw();
  const std::string* username;
  const std::string* password;
  const int32_t* player1_id;
  const int32_t* player2_id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Save_save_data_result__isset {
  _Save_save_data_result__isset() : success(false) {}
  bool success :1;
} _Save_save_data_result__isset;

class Save_save_data_result {
 public:

  Save_save_data_result(const Save_save_data_result&);
  Save_save_data_result& operator=(const Save_save_data_result&);
  Save_save_data_result() : success(0) {
  }

  virtual ~Save_save_data_result() throw();
  int32_t success;

  _Save_save_data_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const Save_save_data_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Save_save_data_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Save_save_data_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Save_save_data_presult__isset {
  _Save_save_data_presult__isset() : success(false) {}
  bool success :1;
} _Save_save_data_presult__isset;

class Save_save_data_presult {
 public:


  virtual ~Save_save_data_presult() throw();
  int32_t* success;

  _Save_save_data_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class SaveClient : virtual public SaveIf {
 public:
  SaveClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  SaveClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t save_data(const std::string& username, const std::string& password, const int32_t player1_id, const int32_t player2_id);
  void send_save_data(const std::string& username, const std::string& password, const int32_t player1_id, const int32_t player2_id);
  int32_t recv_save_data();
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class SaveProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<SaveIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (SaveProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_save_data(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  SaveProcessor(::apache::thrift::stdcxx::shared_ptr<SaveIf> iface) :
    iface_(iface) {
    processMap_["save_data"] = &SaveProcessor::process_save_data;
  }

  virtual ~SaveProcessor() {}
};

class SaveProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  SaveProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< SaveIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< SaveIfFactory > handlerFactory_;
};

class SaveMultiface : virtual public SaveIf {
 public:
  SaveMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<SaveIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~SaveMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<SaveIf> > ifaces_;
  SaveMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<SaveIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t save_data(const std::string& username, const std::string& password, const int32_t player1_id, const int32_t player2_id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->save_data(username, password, player1_id, player2_id);
    }
    return ifaces_[i]->save_data(username, password, player1_id, player2_id);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class SaveConcurrentClient : virtual public SaveIf {
 public:
  SaveConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  SaveConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t save_data(const std::string& username, const std::string& password, const int32_t player1_id, const int32_t player2_id);
  int32_t send_save_data(const std::string& username, const std::string& password, const int32_t player1_id, const int32_t player2_id);
  int32_t recv_save_data(const int32_t seqid);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif
