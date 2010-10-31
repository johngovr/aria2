/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#ifndef D_TRACKER_WATCHER_COMMAND_H
#define D_TRACKER_WATCHER_COMMAND_H

#include "Command.h"
#include "SharedHandle.h"

namespace aria2 {

class DownloadEngine;
class RequestGroup;
class PeerStorage;
class PieceStorage;
class BtRuntime;
class BtAnnounce;
class Option;

class TrackerWatcherCommand : public Command
{
private:
  RequestGroup* requestGroup_;

  DownloadEngine* e_;

  SharedHandle<PeerStorage> peerStorage_;

  SharedHandle<PieceStorage> pieceStorage_;

  SharedHandle<BtRuntime> btRuntime_;

  SharedHandle<BtAnnounce> btAnnounce_;

  SharedHandle<RequestGroup> trackerRequestGroup_;
  /**
   * Returns a command for announce request. Returns 0 if no announce request
   * is needed.
   */
  SharedHandle<RequestGroup> createRequestGroup(const std::string& url);

  std::string getTrackerResponse(const SharedHandle<RequestGroup>& requestGroup);

  void processTrackerResponse(const std::string& response);

  const SharedHandle<Option>& getOption() const;
public:
  TrackerWatcherCommand(cuid_t cuid,
                        RequestGroup* requestGroup,
                        DownloadEngine* e);

  virtual ~TrackerWatcherCommand();

  SharedHandle<RequestGroup> createAnnounce();

  virtual bool execute();

  void setPeerStorage(const SharedHandle<PeerStorage>& peerStorage);

  void setPieceStorage(const SharedHandle<PieceStorage>& pieceStorage);

  void setBtRuntime(const SharedHandle<BtRuntime>& btRuntime);

  void setBtAnnounce(const SharedHandle<BtAnnounce>& btAnnounce);
};

} // namespace aria2

#endif // D_TRACKER_WATCHER_COMMAND_H
